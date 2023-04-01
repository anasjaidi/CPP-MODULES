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


std::pair<std::string, float> BitcoinExchange::parse_line(std::string &) {

}