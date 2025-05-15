C++ = c++
STD = -std=c++11
C++_FLAGS = -Wall -Wextra -Werror
INFILES =	Animal.cpp \
			Dog.cpp \
			Cat.cpp \
			WrongCat.cpp \
			WrongAnimal.cpp \
			Brain.cpp \
			main.cpp

OBJFILES = $(INFILES:.cpp=.o)

NAME = world_on_fire 

all: $(NAME)

$(NAME):$(OBJFILES)
	$(C++) $(STD) $(C++_FLAGS) $(OBJFILES) -o $(NAME) 

%.o: %.cpp
	$(C++) $(STD) $(C++_FLAGS) -c $< -o $@

clean:
	rm -f $(OBJFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
