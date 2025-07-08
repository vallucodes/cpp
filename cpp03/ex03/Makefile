NAME		= diamondtrap
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++11

SRC_DIR		= src/
OBJ_DIR		= obj/

INCLUDES	= -I ./inc
HEADERS		= inc/ClapTrap.hpp \
				inc/ScavTrap.hpp \
				inc/FragTrap.hpp \
				inc/DiamondTrap.hpp

SRCS		= src/main.cpp \
				src/ClapTrap.cpp \
				src/ScavTrap.cpp \
				src/FragTrap.cpp \
				src/DiamondTrap.cpp

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
