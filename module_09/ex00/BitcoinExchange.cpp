//
// Created by Anas Jaidi on 4/1/23.
//

#include "BitcoinExchange.hpp"

BitcoinExchange::~BitcoinExchange() {

}

BitcoinExchange::BitcoinExchange(const std::map<std::string, float> &data, const std::string &infile) {
    this->data = data;
    this->infile.open(infile, std::ios::in);

    if (!this->infile.is_open())
        throw BitcoinExchangeErrors(BitcoinExchangeErrors::ErrorsCodes::FileNotFound);
}

const std::map<std::string, float> &BitcoinExchange::getData() const {
    return data;
}

const std::fstream &BitcoinExchange::getInfile() const {
    return infile;
}

BitcoinExchange::BitcoinExchangeErrors::BitcoinExchangeErrors(int errorCode) : error_code(errorCode) {}

const char *BitcoinExchange::BitcoinExchangeErrors::what() const throw() {
    switch (this->error_code) {
        case FileNotFound:
            return "Error: could not open file.";
            break;
    }
}


std::pair<std::string, float> BitcoinExchange::parse_line(std::string &line) {
    int pos = line.find(',');

    if (pos == -1)
        return (
          std::make_pair("Error", -1)
        );
    else if (pos + 1 == line.length() )
        return (
                std::make_pair("Error", -1)
        );


    std::string date = line.substr(0, pos);

    std::string quantity = line.substr(pos + 1, line.length());

    std::stringstream ss(quantity);

    float q;

    ss >> q;

    if (q < 0 || q > 1000)
        return (
                std::make_pair("Error", -1)
        );
    if (!this->valid_date(date))
        return (
                std::make_pair("Error", -1)
        );

    return (
            std::make_pair(date, q)
    );
}

bool BitcoinExchange::valid_date(std::string &date) {
    int count = std::count(date.begin(), date.end(), '-');

    if (count != 2)
        return false;

    int pos = date.find('-', 0), oldpos = pos;

    int year = std::stoi(date.substr(0, pos));

    pos = date.find('-', pos + 1);

    int  month = std::stoi(std::string(date.data() + oldpos + 1, pos - oldpos - 1));

    int day = std::stoi(date.substr(pos + 1, date.length()));


    if (month < 1 || month > 12) {
        return false;
    }

    // check if day is valid
    if (day < 1 || day > 31) {
        return false;
    } else if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
            if (day > 29) {
                return false;
            }
        } else {
            if (day > 28) {
                return false;
            }
        }
    } else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) { // check for 30-day months
        return false;
    }

    // check if year is valid
    if (year < 2008) {
        return false;
    } else if (year == 2008 && month == 01 && day == 1)
        return false;
    return true;
}

std::string BitcoinExchange::get_line() {
    std::string line;
    std::getline(this->infile, line);
    return line;
}