//
// Created by Anas Jaidi on 4/2/23.
//

#include "RPN.hpp"


bool RPN::operate(char oper) {


    if (oper == '+') {

        this->add();
    } else if (oper == '-') {
        this->subtract();

    } else if (oper == '*') {
        this->multiply();

    } else if (oper == '/') {
        this->divide();

    } else {
        return false;
    }
    return true;
}

void RPN::push_to_stack(int num) {
    this->nums.push(num );
}

const int &RPN::get_top() {
    const int &num = nums.top();
    this->nums.pop();
    return num;
}

void RPN::add() {
    int num_b = this->get_top();
    int num_a = this->get_top();
    push_to_stack(num_a + num_b);
}

void RPN::multiply() {
    int num_b = this->get_top();
    int num_a = this->get_top();
    push_to_stack(num_a * num_b);
}

void RPN::divide() {
    int num_b = this->get_top();
    int num_a = this->get_top();
    push_to_stack(num_a / num_b);
}

void RPN::subtract() {
    int num_b = this->get_top();
    int num_a = this->get_top();
    push_to_stack(num_a - num_b);
}