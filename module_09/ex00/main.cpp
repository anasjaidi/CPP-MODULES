//
// Created by Anas Jaidi on 4/1/23.
//


# include <iostream>
# include <filesystem>
#include <fstream>


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
    return 0;
}