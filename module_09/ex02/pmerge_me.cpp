//
// Created by Anas Jaidi on 4/2/23.
//

#include "pmerge_me.hpp"


void PmergeMe::add_num(int &num) {
    list_add_num(num);
    vec_add_num(num);
}


void PmergeMe::list_add_num(int &num) {
    this->list.push_back(num);
}


void PmergeMe::vec_add_num(int &num) {
    this->vec.push_back(num);
}