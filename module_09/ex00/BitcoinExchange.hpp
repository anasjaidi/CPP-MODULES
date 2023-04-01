//
// Created by Anas Jaidi on 4/1/23.
//

#ifndef MODULE_09_BITCOINEXCHANGE_HPP
#define MODULE_09_BITCOINEXCHANGE_HPP
# include <iostream>
# include <fstream>
# include <map>

# include <sstream>


class BitcoinExchange {
private:
    std::map<std::string, float> data;
    std::fstream infile;
public:
    BitcoinExchange(const std::map<std::string, float> &data, const std::string &infile);

    const std::map<std::string, float> &getData() const;

    const std::fstream &getInfile() const;

    virtual ~BitcoinExchange();

class BitcoinExchangeErrors : public std::exception {
public:
    enum ErrorsCodes {
        FileNotFound,
    };

    explicit BitcoinExchangeErrors(int errorCode);

    const char * what() const throw() override;


private:
    int error_code;
};
};


#endif //MODULE_09_BITCOINEXCHANGE_HPP
