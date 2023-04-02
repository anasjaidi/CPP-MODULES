//
// Created by Anas Jaidi on 4/2/23.
//

# include "pmerge_me.hpp"

int main (int ac, char **av) {

    PmergeMe merge;

    for (int i = 0; i < ac; ++i) {
        int  num = atoi(av[i]);
        merge.add_num(num);
    }
    if (merge.vec_is_sorted()) {
        std::cerr << "Error: Numbers are sorted." << std::endl;
        return 1;
    }

    merge.render_list_nums();
    merge.render_vec_nums();
    return (0);
}
