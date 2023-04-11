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

void PmergeMe::sort_vec() {
    split_vec(vec);
}

void PmergeMe::split_vec(std::vector<int> &arr) {
    if (arr.size() <= 1)
        return ;
    std::vector<int> rhs;
    create_sub_vec(rhs, arr, 0, (int)(arr.size() / 2));
    std::vector<int> lhs;
    create_sub_vec(lhs, arr, (int)(arr.size() / 2), (int)arr.size());
    split_vec(rhs);
    split_vec(lhs);
    merge_vec(rhs, lhs, arr);
}

void PmergeMe::merge_vec(std::vector<int> &rhs, std::vector<int> &lhs, std::vector<int> &arr) {
    int i = 0, l = 0, r = 0;

    while (l < lhs.size() && r < rhs.size()) {
        if (lhs[l] > rhs[r]) {
            arr[i++] = rhs[r++];
        } else {
            arr[i++] = lhs[l++];
        }
    }

    while (l < lhs.size()) {
        arr[i++] = lhs[l++];
    }

    while (r < rhs.size()) {
        arr[i++] = rhs[r++];
    }
}

void PmergeMe::sort_list() {
    split_list(list);
}

void PmergeMe::split_list(std::list<int> &arr) {
    if (arr.size() <= 1)
        return ;
    std::list<int> rhs;
    create_sub_list(rhs, arr, 0, (int)(arr.size() / 2));
    std::list<int> lhs;
    create_sub_list(lhs, arr, (int)(arr.size() / 2), (int)arr.size());

    split_list(rhs);
    split_list(lhs);
    merge_list(rhs, lhs, arr);
}

void PmergeMe::create_sub_vec(std::vector<int> &to, std::vector<int> &from, int f, int t) {
    for (int i = f; i < t; i++) {
        to.push_back(from[i]);
    }
}

void PmergeMe::create_sub_list(std::list<int> &to, std::list<int> &from, int f, int t) {
    std::list<int>::iterator it_f = from.begin();
    std::advance(it_f, f);

    for (int i = f; i < t; ++i) {
        to.push_back(*it_f);
    }
}

void PmergeMe::merge_list(std::list<int> &rhs, std::list<int> &lhs, std::list<int> &arr) {
    std::list<int>::iterator it_arr = arr.begin();
    std::list<int>::iterator it_rhs = rhs.begin();
    std::list<int>::iterator it_lhs = lhs.begin();

    while (it_lhs != lhs.end() && it_rhs != rhs.end()) {
        if (*it_lhs > *it_rhs) {
            arr.insert(it_arr, *it_rhs);
            it_rhs++;
            it_arr++;
        } else {
            arr.insert(it_arr, *it_lhs);
            it_lhs++;
            it_arr++;
        }
    }

    while (it_lhs != lhs.end()) {
        arr.insert(it_arr, *it_lhs);
        it_arr++;
        it_lhs++;
    }
    while (it_rhs != rhs.end()) {
        arr.insert(it_arr, *it_rhs);
        it_arr++;
        it_rhs++;
    }

}