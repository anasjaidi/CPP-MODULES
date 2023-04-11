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

    void sort_vec();
    void split_vec(std::vector<int> &arr);
    void merge_vec(std::vector<int> &rhs, std::vector<int> &lhs, std::vector<int> &arr);
    void sort_list();
    void split_list(std::list<int> &arr);
    void merge_list(std::list<int> &rhs, std::list<int> &lhs, std::list<int> &arr);

    void create_sub_vec(std::vector<int> &to, std::vector<int> &from, int f, int t);
    void create_sub_list(std::list<int> &to, std::list<int> &from, int f, int t);
};


#endif //FT_IRC_PMERGE_ME_HPP
