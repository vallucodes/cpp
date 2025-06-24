NAME		= megaphone
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++11

SRCS		= megaphone.cpp

all: $(NAME)

$(NAME): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(SRCS)

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all, fclean, re
