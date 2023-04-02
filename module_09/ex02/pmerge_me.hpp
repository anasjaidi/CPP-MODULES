//
// Created by Anas Jaidi on 4/2/23.
//

#ifndef FT_IRC_PMERGE_ME_HPP
#define FT_IRC_PMERGE_ME_HPP

# include <iostream>

# include <libc.h>

# include <vector>

# include <list>


class PmergeMe {
private:
    std::vector<int> vec;
    std::list<int> list;
public:
    void vec_add_num(int &num);
    void list_add_num(int &num);
    void add_num(int &num);

    void render_vec_nums();
    void render_list_nums();

    bool vec_is_sorted();
    bool list_is_sorted();
};


#endif //FT_IRC_PMERGE_ME_HPP
