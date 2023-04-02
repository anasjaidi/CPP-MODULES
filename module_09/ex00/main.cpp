//
// Created by Anas Jaidi on 4/1/23.
//


# include "BitcoinExchange.hpp"


std::pair<std::string, float> parse_line(std::string &line) {

    float price;
    std::istringstream ss(line.substr(line.find(',') + 1, line.length()));
    std::string date;

    date = line.substr(0, line.find(','));

    ss >> price;

    return std::make_pair(date, price);
}

std::map<std::string, float> store_data(std::fstream &infile) {

    std::string line;
    std::map<std::string, float> data;

    std::getline(infile, line);

    while (std::getline(infile, line)) {
        std::pair<std::string, float> parsed_line = parse_line(line);
        data[parsed_line.first] = parsed_line.second;
    }

    return data;
}

bool is_all_spaces(std::string &line) {
    for (int i = 0; i < line.length(); ++i) {
        if (!std::isspace(line[i])) return false;
    }
    return true;
}


int main(int ac, char **av) {
    if (ac > 2)
        return (
                std::cout << "args Error" << std::endl,
                1
        );
    else if (ac == 1)
        return (
                std::cout << "Error: could not open file." << std::endl,
                        1
        );

    std::string in_file(av[1]);

    std::fstream data_file("data.csv");

    if (!data_file.is_open())
        return (
                std::cout << "Error: could not open file." << std::endl,
                        1
        );

    /*
     * Everything works fine if the program rich this point
     * **/

    std::map<std::string, float> data = store_data(data_file);


    try {

        BitcoinExchange  *btc = new BitcoinExchange(data, in_file);

        std::string line = btc->get_line();

        while (!(btc->getInfile().eof() && line.empty())) {

            if (line.empty() || is_all_spaces(line)) {
                line = btc->get_line();
                continue;
            }

            std::pair<std::string, float>r = btc->parse_line(line);

            line = btc->get_line();

        }
    } catch (std::exception &err) {

        std::cerr << err.what() << std::endl;

    }

    return 0;
}