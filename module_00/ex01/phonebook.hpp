#pragma once
#include <iostream>
#include <string>

class number {
    protected:
    std::string fname, lname, nickname, d_secret;
    long long phone;
    public:
    number(std::string c_fname, std::string c_lname, std::string c_nickname, std::string c_d_secret, long long c_phone)
    {
        fname = c_fname;
        lname = c_lname;
        nickname = c_nickname;
        d_secret = c_d_secret;
        phone = c_phone;
    }
    void print(int j)
    {
        std::cout.width(10);
        std::cout << j + 1 << " | " << fname << " | " << lname << " | " << nickname << " | " <<phone <<  " | " << d_secret << std::endl;
    }
    int is_empty() { if (fname.empty()) return 1; return 0; }
};
class numbers: public number {

};