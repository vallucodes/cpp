#pragma once
#include "Weapon.hpp"
#include <iostream>

class HumanA
{
	private:
		std::string	_Name;
		Weapon& 	_Weapon;

	public:
		HumanA(std::string name, Weapon& weapon);
		~HumanA();
		void	attack();
};
