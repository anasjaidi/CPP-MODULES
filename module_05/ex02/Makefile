name = Fixed
flags = -Wall -Wextra -Werror -std=c++98 
src =  Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp

obj = $(src:%.cpp=%.o)

all : $(name)

$(name): $(obj) main.cpp
	c++ $(flags) main.cpp  $(obj) -o $(name)

%.o: %.cpp Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp
	c++ $(flags) -c $< -o $@

clean:
	rm -rf $(obj)

fclean: clean
	rm -f $(name)

re:	fclean all