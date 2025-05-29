#include <iostream>

void	megaphone(std::string msg)
{
	for (size_t i = 0; msg[i]; i++)
		std::cout << static_cast<unsigned char>(std::toupper(static_cast<unsigned char>(msg[i])));
}

int main(int ac, char **av) {
	if (ac == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}
	else
	{
		for (int i = 1; i < ac; i++)
			megaphone(std::string(av[i]));
	}
	std::cout << std::endl;
	return (0);
}
