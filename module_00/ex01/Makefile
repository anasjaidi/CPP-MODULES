name = phonebook
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 
src = phone.cpp

obj = $(src:%.cpp=%.o)

all : $(name)

$(name): $(obj) phonebook.hpp
	g++ $(CXXFLAGS) $(obj) -o $(name)


clean:
	rm -rf $(obj)

fclean: clean
	rm -f $(name)

re:	fclean all