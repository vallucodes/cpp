NAME		= Animal
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++11

SRC_DIR		= src/
OBJ_DIR		= obj/

INCLUDES	= -I ./inc
HEADERS		= inc/Animal.hpp \
				inc/Brain.hpp \
				inc/Cat.hpp \
				inc/Dog.hpp \
				inc/WrongAnimal.hpp \
				inc/WrongCat.hpp

SRCS		= src/main.cpp \
				src/Animal.cpp \
				src/Brain.cpp \
				src/Cat.cpp \
				src/Dog.cpp \
				src/WrongAnimal.cpp \
				src/WrongCat.cpp \

OBJS		= $(patsubst $(SRC_DIR)%.cpp,$(OBJ_DIR)%.o,$(SRCS))

all: $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(OBJS) $(INCLUDES) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp $(HEADERS)
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
