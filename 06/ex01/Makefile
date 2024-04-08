NAME = Serializer
OBJS = $(SRCS:.cpp=.o)
CXX = clang++
CXXFLAGS = -Wall -Wextra -Werror -Wshadow -Wno-shadow -I include # -std=c++98 

SRC_FILES = Serializer.cpp
SRCS = $(addprefix src/, $(SRC_FILES)) main.cpp

INCLUDE_FILES = Serializer.hpp
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
	rm -f *_shrubbery

re: fclean all

.PHONY: all clean fclean re