#include "RPN.hpp"
#include <iostream>
#include <sstream>
#include <limits>

bool	validInput( char c ) {
	return (c == '*' || c == '/' || c == '+' || c == '-' || (c >= '0' && c <= '9'));
}

void	inputValidation( std::string input ) {
	std::istringstream iss(input);
	char c;
	while (iss >> c)
	{
		if (!validInput(c))
			throw std::runtime_error(std::string("Error: Invalid token in notation: ") + c);
	}
	// cont.getStack().push(9);
	// cont.getStack().pop();
}

void	checkSubstractionOverflow( int nb1, int nb2 ) {
	if (nb1 < 0 && nb2 > 0)
	{
		if (std::numeric_limits<int>::lowest() + nb2 > nb1)
			throw std::runtime_error("Error: overflow");
	}
	if (nb1 > 0 && nb2 < 0)
	{
		if (std::numeric_limits<int>::max() + nb2 < nb1)
			throw std::runtime_error("Error: overflow");
	}
}

void	checkAdditionOverflow( int nb1, int nb2 ) {
	if (nb1 < 0 && nb2 < 0)
	{
		if (std::numeric_limits<int>::lowest() + nb2 > nb1)
			throw std::runtime_error("Error: overflow");
	}
	if (nb1 > 0 && nb2 > 0)
	{
		if (std::numeric_limits<int>::max() - nb2 < nb1)
			throw std::runtime_error("Error: overflow");
	}
}

void	checkMultiplicationOverflow( int nb1, int nb2 ) {
	if (nb1 == 0 || nb2 == 0)
		return ;
	if (nb1 == -1 && nb2 == std::numeric_limits<int>::lowest())
		throw std::runtime_error("Error: overflow");
	if (nb1 != 0 && nb1 < 0 && (nb2 < std::numeric_limits<int>::max() / nb1))
		throw std::runtime_error("Error: overflow");
	if (nb1 != 0 && nb1 < 0 && (nb2 > std::numeric_limits<int>::lowest() / nb1))
		throw std::runtime_error("Error: overflow");
	if (nb1 != 0 && nb1 > 0 && (nb2 > std::numeric_limits<int>::max() / nb1))
		throw std::runtime_error("Error: overflow");
	if (nb1 != 0 && nb1 > 0 && (nb2 < std::numeric_limits<int>::lowest() / nb1))
		throw std::runtime_error("Error: overflow");
}

int	calculate( int nb1, int nb2, char op ) {
	int res;

	if (op == '-')
	{
		res = nb1 - nb2;
		checkSubstractionOverflow(nb1, nb2);
		return res;
	}
	else if (op == '+')
	{
		res = nb1 + nb2;
		checkAdditionOverflow(nb1, nb2);
		return res;
	}
	else if (op == '*')
	{
		res = nb1 * nb2;
		checkMultiplicationOverflow(nb1, nb2);
		return res;
	}
	else if (op == '/')
	{
		if (nb2 == 0)
			throw std::runtime_error("Error: division by 0");
		res = nb1 / nb2;
		return res;
	}
	else
		throw std::runtime_error("Error: unreachable code");
}

bool	isNb(char c) {
	return (c >= '0' && c <= '9');
}

void	calculation( std::string input ) {
	RPN stack;

	std::istringstream iss(input);
	char c;
	while (iss >> c)
	{
		if (isNb(c))
		{
			std::string s = std::string(1, c);
			stack.getStack().push(std::stoi(s));
		}
		else
		{
			if (stack.getStack().size() < 2)
				throw std::runtime_error("Error: operators not balanced with numbers");
			int nb1 = stack.getStack().top();
			stack.getStack().pop();
			int nb2 = stack.getStack().top();
			stack.getStack().pop();
			int res = calculate(nb1, nb2, c);
			stack.getStack().push(res);
		}
	}
}

int	main(int ac, char **av)
{
	if (ac != 2) {
		std::cout << "Usage: ./RPN <reverse polish notation>" << std::endl;
		return 1;
	}
	try {
		inputValidation(av[1]);
		calculation(av[1]);
	}
	catch (std::runtime_error& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
