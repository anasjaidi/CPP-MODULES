//
// Created by Anas Jaidi on 4/2/23.
//

#ifndef FT_IRC_RPN_H
#define FT_IRC_RPN_H

# include <iostream>
# include <stack>


class RPN {
private:
    std::stack<int> nums;
public:
    bool operate(char oper);
    void push_to_stack(int num);
    const int &get_top();
    void multiply();
    void subtract();
    void divide();
    void add();
};


#endif //FT_IRC_RPN_H
