#include "RPN.hpp"
#include <iostream>

void	inputValidation(char **av) {
	(void)av;
	RPN cont;

	cont.getStack().push(9);
	cont.getStack().pop();
}

int	main(int ac, char **av)
{
	if (ac > 21) {
		std::cout << "Usage: ./RPN <operators and max 10 numbers>" << std::endl;
		return 1;
	}
	inputValidation(av);
	// calculation(av);
	return 0;
}
