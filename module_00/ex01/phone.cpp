#include "./phonebook.hpp"
numbers phones[8];

void print_numbers()
{
    std::cout.width(10);
    std::cout << "index | "<< "first-name | " << "last-name | " << "nickname | " << "phone | " << "darckest-secret"<< std::endl;
    for (int j = 0; !phones[j].is_empty(); j++){
        phones[j].print(j);
    }
}

void    add()
{
    static int i;
    std::string fname, lname, nickname, d_secre, s_phone;
    long long phone;
    std::cout << "enter first-name: ";
    getline(std::cin, fname);
    if (!std::cin.good())
            return ;
    if (fname.empty())
        {std::cout << "first name can't be empty" << std::endl; return ;} 
    std::cout << "enter last-name: ";
    getline(std::cin, lname);
    if (!std::cin.good())
            return ;
    if (lname.empty())
        {std::cout << "last name can't be empty" << std::endl ;return ;}
    std::cout << "enter nickname: ";
    getline(std::cin, nickname);
    if (!std::cin.good())
            return ;
    if (nickname.empty())
        {std::cout << "nickname can't be empty" << std::endl ;return ;}
    std::cout << "enter phone number: ";
    getline(std::cin, s_phone);
    if (!std::cin.good())
            return ;
    if (s_phone.empty())
        {std::cout << "phone number can't be empty" << std::endl ;return ;}
    try{

        phone = stoi(s_phone);
    }
    catch(std::exception& e) {
        std::cout << e.what()<<std::endl;
        return ;
    }
    std::cout << "enter darckest secret: ";
    getline(std::cin, d_secre);
    if (!std::cin.good())
            return ;
    if (d_secre.empty())
        {std::cout << "first darckest secret can't be empty" << std::endl;return ;}
    number ph(fname, lname, nickname, d_secre, phone);
    phones[i % 8];
    i++;
}
void    search()
{
    std::string in;
    print_numbers();
    std::cout << "enter the index of contact-> ";
    getline(std::cin,in);
    int index=0;
    try{

        index = stoi(in);
    }
    catch(std::exception& e) {
        std::cout << e.what()<<std::endl;
        return ;
    }
    if (index <= 0 || index > 8)
        {std::cout << "out of range" << std::endl; return;}
    index--;
    if (phones[index].is_empty()) {std::cout << "contact is empty" << std::endl; return;}
    std::cout.width(10);
    std::cout << "index | "<< "first-name | " << "last-name | " << "nickname | " << "phone | " << "darckest-secret"<< std::endl;
    phones[index].print(index);
}

int main()
{
    std::string line;
    while (true)
    {
        std::cout << "phonebook-> ";
        getline(std::cin, line);
        if (!std::cin.good())
            return 0;
        if (!line.compare("ADD"))
            add();
        else if (!line.compare("SEARCH"))
            search();
        else if (!line.compare("EXIT"))
            break ;
        else
            std::cout << "available commands => ADD, SEARCH, EXIT" << std::endl;
    }
}
