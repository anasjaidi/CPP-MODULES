name = Zombie
flags = -Wall -Wextra -Werror -std=c++98 
src = HumanA.cpp HumanB.cpp Weapon.cpp

obj = $(src:%.cpp=%.o)

all : $(name)

$(name): $(obj) main.cpp
	g++ $(flags) main.cpp  $(obj) -o $(name)

%.o: %.cpp HumanA.hpp  HumanB.hpp Weapon.hpp
	g++ $(flags) -c $< -o $@

clean:
	rm -rf $(obj)

fclean: clean
	rm -f $(name)

re:	fclean all