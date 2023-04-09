//
// Created by Anas Jaidi on 4/2/23.
//

# include "RPN.hpp"



int main(int ac, char **av) {
    if (ac != 2) {
        std::cerr << "Error: bad arguments." << std::endl;
    }

    std::string line = av[1];

    RPN *rpn = new RPN();

    int found_in_begin = true;

    try {
        for (int i = 0; i < line.length(); ++i) {

            if (std::isspace(line[i]))
                continue;
            else if (std::isdigit(line[i])) {
                found_in_begin = false;
                rpn->push_to_stack(line[i] - 48);

            } else if (!(rpn->operate(line[i])) || found_in_begin){

                std::cerr << "Error" << std::endl;
                return 1;
            }
        }

    } catch (std::exception &err) {
        return (
                std::cerr << "Error." << std::endl,
                1
            );
    }

    if (rpn->getNums().size() != 1) return (
            std::cerr << "operator is missing" << std::endl,
            1
    );
    std::cout << rpn->get_top() << std::endl;
}