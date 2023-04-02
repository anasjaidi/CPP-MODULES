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

void PmergeMe::render_list_nums() {
    for (int num : this->list) {

        std::cout << num;

        if (num != this->list.back()) std::cout << " ";
    }
    std::cout << std::endl;
}


void PmergeMe::render_vec_nums() {
    for (int num : this->vec) {
        std::cout << num;

        if (num != this->vec.back()) std::cout << " ";
    }
    std::cout << std::endl;
}

bool PmergeMe::vec_is_sorted() {

    if (this->vec.empty()) return true;

    for (int i = 0; i < this->vec.size() - 1; ++i) {
        if (this->vec[i] > this->vec[i + 1])
            return false;
    }
    return true;
}

bool PmergeMe::list_is_sorted() {

    if (this->list.empty()) return true;

    std::list<int>::iterator it = this->list.begin();
    std::list<int>::iterator second = it;

    second++;

    for (; second != this->list.end(); it++, second++) {
        if (*it > *second) return false;
    }
    return true;
}