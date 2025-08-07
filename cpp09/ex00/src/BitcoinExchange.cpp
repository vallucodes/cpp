#include "BitcoinExchange.hpp"
#include <fstream>
#include <chrono>

BitcoinExchange::BitcoinExchange( void ) {
	loadDatabase();
}


void	BitcoinExchange::loadDatabase( void ) {
	std::ifstream database("data/data.csv");
	if (!database.is_open())
		throw std::runtime_error("Error: could not open database for reading");

	std::string line;
	while (1)
	{
		if(!std::getline(database, line))
			break ;
		if (line == "date,exchange_rate")
			continue ;
		size_t comma_pos = line.find(',');
		std::string key = line.substr(0, comma_pos);
		std::string value = line.substr(comma_pos + 1);
		data[key] = std::stof(value);
	}
}

std::map<std::string, float>	BitcoinExchange::getDatabase( void ) const {
	return (data);
}

void	BitcoinExchange::printDatabase() const {
	for (const auto& pair : data) {
		std::cout << pair.first << " => " << pair.second << std::endl;
	}
}
