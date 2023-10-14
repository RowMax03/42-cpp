NAME = Unnecessary_violence
OBJS = $(SRCS:.cpp=.o)
CXX = clang++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -I include

SRC_FILES = HumanA.cpp HumanB.cpp Weapon.cpp 
SRCS = $(addprefix src/, $(SRC_FILES)) main.cpp

INCLUDE_FILES = HumanA.hpp HumanB.hpp Weapon.hpp
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