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

bool BitcoinExchange::valid_quantity(std::string &quantity) {

    int i = 0;

    quantity = quantity.substr(quantity.find_first_not_of(" \\t\\n\\v\\f\\r"));
    quantity = quantity.substr(0, quantity.find_last_not_of(" \\t\\n\\v\\f\\r") + 1);
    if (quantity[i] == '+') i++;

    int dot_count = std::count(quantity.begin(), quantity.end(), '.');

    if (dot_count > 1) return false;

    while (i < quantity.length()) {
        if (!std::isdigit(quantity[i]) && quantity[i] != '.') return false;
        i++;
    }


    return true;
}

bool BitcoinExchange::check_first_line_if_valid(std::string &quantity) {
    int pipes_count = std::count(quantity.begin(), quantity.end(), '|');

    int pos = quantity.find('|');

    if (pipes_count != 1 || pos == -1) return false;

    std::string date = quantity.substr(0, pos);

    date = date.substr(date.find_first_not_of(" \t\n\v\f\r"));
    date = date.substr(0, date.find_last_not_of(" \t\n\v\f\r") + 1);

    std::string q = quantity.substr(pos + 1, quantity.length());

    q = q.substr(q.find_first_not_of(" \t\n\v\f\r"));
    q = q.substr(0, q.find_last_not_of(" \t\n\v\f\r") + 1);

    if (date != "date" || q != "value") return false;

    return true;


}

std::pair<std::string, float> BitcoinExchange::parse_line(std::string &line) {
    int pos = line.find('|');

    if (line.find('|', pos + 1) != -1)
        return (
                std::make_pair("Error: bad arguments", -1)
        );

    line = line.substr(line.find_first_not_of(" \t\n\v\f\r"));
    line = line.substr(0, line.find_last_not_of(" \t\n\v\f\r") + 1);

    if (pos == -1)
        return (
          std::make_pair("Error: no quantity", -1)
        );
    else if (pos + 1 == line.length() )
        return (
                std::make_pair("Error: no quantity", -1)
        );


    std::string date = line.substr(0, pos);

    std::string quantity = line.substr(pos + 1, line.length());

    if (!valid_quantity(quantity))
        return (
                std::make_pair("Error: invalid quantity", -1)
        );

    std::stringstream ss(quantity);

    float q;

    ss >> q;

    if (q < 0 || q > 1000)
        return (
                std::make_pair("Error: number is To High", -1)
        );
    if (!this->valid_date(date))
        return (
                std::make_pair("Error: date is not valid", -1)
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

    std::string year_str = date.substr(0, pos);

    int year = std::stoi(year_str.empty() ? "0" : year_str);

    pos = date.find('-', pos + 1);

    std::string month_str = date.substr(oldpos + 1, (pos - oldpos - 1));

    int  month = std::stoi(month_str.empty() ? "0" : month_str);

    std::string day_str = date.substr(pos + 1, date.length());

    int day = std::stoi(day_str.empty() ? "0" : day_str);


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
    if (year < 2008 || year > 9999) {
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