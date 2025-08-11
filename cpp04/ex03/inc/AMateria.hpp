#pragma once
#include "ICharacter.hpp"
#include <iostream>

class AMateria {

	protected:
		std::string type;

	public:
		AMateria( void );
		AMateria( std::string const & type );
		AMateria( const AMateria& other );
		AMateria& operator=( const AMateria& other );
		virtual ~AMateria( void );

		std::string const &	getType( void ) const;
		virtual AMateria*	clone( void ) const = 0;
		virtual void		use( ICharacter& target );
};
