NAME		= soManyForms
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++11

SRC_DIR		= src/
OBJ_DIR		= obj/

INCLUDES	= -I ./inc
HEADERS		= inc/Bureaucrat.hpp \
				inc/AForm.hpp \
				inc/PresidentialPardonForm.hpp \
				inc/RobotomyRequestForm.hpp \
				inc/ShrubberyCreationForm.hpp

SRCS		= src/main.cpp \
				src/AForm.cpp \
				src/Bureaucrat.cpp \
				src/PresidentialPardonForm.cpp \
				src/RobotomyRequestForm.cpp \
				src/ShrubberyCreationForm.cpp

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
