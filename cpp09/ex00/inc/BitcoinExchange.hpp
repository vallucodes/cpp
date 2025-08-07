#pragma once
#include <iostream>
#include <map>

class BitcoinExchange {

	private:
		std::map<std::string, float>	data;

	public:
		BitcoinExchange( void );
		BitcoinExchange( const BitcoinExchange& other ) = delete;
		BitcoinExchange& operator=( const BitcoinExchange& other ) = delete;
		~BitcoinExchange( void ) = default;

		void							loadDatabase( void );
		void							printDatabase( void ) const;
		std::map<std::string, float>	getDatabase( void ) const;
};
