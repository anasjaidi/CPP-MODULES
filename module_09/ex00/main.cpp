//
// Created by Anas Jaidi on 4/1/23.
//


# include <iostream>
# include <filesystem>
# include <fstream>
# include <map>

# include <sstream>


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

    std::fstream infile(in_file.c_str());
    std::fstream data_file("data.csv");

    if (!infile.is_open())
        return (
                std::cout << "Error: could not open file." << std::endl,
                        1
        );
    if (!data_file.is_open())
        return (
                std::cout << "Error: could not open file." << std::endl,
                        1
        );

    /*
     * Everything works fine if the program rich this point
     * **/

    std::map<std::string, float> data = store_data(data_file);

    for (std::map<std::string, float>::iterator it = data.begin(); it != data.end(); it++) {
        std::cout << it->first << " | " << it->second << std::endl;
    }

    return 0;
}