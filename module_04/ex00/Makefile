name = Fixed
flags = -Wall -Wextra -Werror -std=c++98 
src =  Animal.cpp Dog.cpp Cat.cpp WrongCat.cpp WrongAnimal.cpp

obj = $(src:%.cpp=%.o)

all : $(name)

$(name): $(obj) main.cpp
	c++ $(flags) main.cpp  $(obj) -o $(name)

%.o: %.cpp Animal.hpp Dog.hpp Cat.hpp WrongCat.hpp WrongAnimal.hpp
	c++ $(flags) -c $< -o $@

clean:
	rm -rf $(obj)

fclean: clean
	rm -f $(name)

re:	fclean all