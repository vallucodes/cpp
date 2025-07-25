#include <iostream>
#include "Data.hpp"
#include "Serializer.hpp"

void	test1() {
	Data a;

	uintptr_t raw = Serializer::serialize(&a);
	std::cout << &a << std::endl;
	std::cout << std::hex << "0x" << raw << std::dec << std::endl;
	std::cout << raw << std::endl;

	Data *b = Serializer::deserialize(raw);
	std::cout << b << std::endl;
}

int main()
{
	test1();
	return 0;
}
