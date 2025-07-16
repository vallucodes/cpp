#pragma once
#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include <iostream>

#define MAT_INV_SIZE 4

class MateriaSource : public IMateriaSource {

	private:
		AMateria	*inventory[MAT_INV_SIZE];

	public:
		MateriaSource( void );
		MateriaSource( const MateriaSource& other );
		MateriaSource& operator=( const MateriaSource& other );
		~MateriaSource();

		void		learnMateria(AMateria*);
		AMateria*	createMateria(std::string const & type);
};
