//
// Created by Anas Jaidi on 4/2/23.
//

#ifndef FT_IRC_PMERGE_ME_HPP
#define FT_IRC_PMERGE_ME_HPP

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
};


#endif //FT_IRC_PMERGE_ME_HPP
