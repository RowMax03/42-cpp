NAME = ClapTrap
OBJS = $(SRCS:.cpp=.o)
CXX = clang++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -I include

SRC_FILES = ClapTrap.cpp
SRCS = $(addprefix src/, $(SRC_FILES)) main.cpp

INCLUDE_FILES = ClapTrap.hpp
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
