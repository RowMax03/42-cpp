NAME = Interface
OBJS = $(SRCS:.cpp=.o)
CXX = clang++
CXXFLAGS = -Wall -Wextra -Werror -Wshadow -Wno-shadow -std=c++98 -I include

SRC_FILES = AMateria.cpp Character.cpp Cure.cpp Ice.cpp  MateriaSource.cpp
SRCS = $(addprefix src/, $(SRC_FILES)) main.cpp

INCLUDE_FILES = AMateria.hpp Character.hpp Cure.hpp Ice.hpp ICharacter.hpp IMateriaSource.hpp MateriaSource.hpp Include.hpp
INCLUDES = $(addprefix include/, $(INCLUDE_FILES))

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
obj/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re