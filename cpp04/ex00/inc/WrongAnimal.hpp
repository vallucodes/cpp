#pragma once
#include <iostream>

class WrongAnimal {
	protected:
		std::string type;

	public:
		WrongAnimal( void );
		WrongAnimal( const WrongAnimal& other );
		WrongAnimal& operator=( const WrongAnimal& other );
		virtual ~WrongAnimal( void );
		
		virtual	void	makeSound ( void ) const;
		void			setType( std::string type );
		std::string		getType( void ) const;
};


