NAME		= hi_this_is_brain
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++11

OBJ_DIR		= obj/

SRCS		= main.cpp
OBJS		= $(patsubst %.cpp,$(OBJ_DIR)%.o,$(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
