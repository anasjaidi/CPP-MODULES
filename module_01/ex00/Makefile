name = Zombie
flags = -Wall -Wextra -Werror -std=c++98 
src =  newZombie.cpp randomChump.cpp Zombie.cpp

obj = $(src:%.cpp=%.o)

all : $(name)

$(name): $(obj) main.cpp
	g++ $(flags) main.cpp  $(obj) -o $(name)

%.o: %.cpp Zombie.hpp
	g++ $(flags) -c $< -o $@

clean:
	rm -rf $(obj)

fclean: clean
	rm -f $(name)

re:	fclean all