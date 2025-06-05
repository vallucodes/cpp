#include "Harl.hpp"
#include <iostream>

void	test1( void ) {
	Harl	harl;

	std::cout << "Testing DEBUG level\n";
	std::cout << std::string(35, '-') << std::endl;
	harl.complain( "DEBUG" );
	std::cout << std::endl << std::endl;
}

void	test2( void ) {
	Harl	harl;

	std::cout << "Testing INFO level\n";
	std::cout << std::string(35, '-') << std::endl;
	harl.complain( "INFO" );
	std::cout << std::endl << std::endl;
}

void	test3( void ) {
	Harl	harl;

	std::cout << "Testing WARNING level\n";
	std::cout << std::string(35, '-') << std::endl;
	harl.complain( "WARNING" );
	std::cout << std::endl << std::endl;
}

void	test4( void ) {
	Harl	harl;

	std::cout << "Testing ERROR level\n";
	std::cout << std::string(35, '-') << std::endl;
	harl.complain( "ERROR" );
	std::cout << std::endl << std::endl;
}

void	test5( void ) {
	Harl	harl;

	std::cout << "Testing invalid level\n";
	std::cout << std::string(35, '-') << std::endl;
	harl.complain( "ASDASD" );
	std::cout << std::endl << std::endl;
}

void	test6( void ) {
	Harl	harl;

	std::cout << "Testing empty string level\n";
	std::cout << std::string(35, '-') << std::endl;
	harl.complain( "" );
	std::cout << std::endl << std::endl;
}

void	test7( void ) {
	Harl	harl;

	std::cout << "Testing partially correct level\n";
	std::cout << std::string(35, '-') << std::endl;
	harl.complain( "INFO123" );
	std::cout << std::endl << std::endl;
}

void	tests( void ) {
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
}
