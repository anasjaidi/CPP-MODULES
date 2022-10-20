name = Zombie
flags = -Wall -Wextra -Werror -std=c++98 
src = main.cpp  Zombie.cpp zombieHorde.cpp

obj = $(src:%.cpp=%.o)

all : $(name)

$(name): $(obj) Zombie.hpp
	g++ $(flags) $(obj) -o $(name)

clean:
	rm -rf $(obj)

fclean: clean
	rm -f $(name)

re:	fclean all