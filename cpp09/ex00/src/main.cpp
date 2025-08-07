#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>

void	findKey( std::string line, const BitcoinExchange& data ) {
	size_t pipe_pos = line.find('|');
	std::string value_str = line.substr(pipe_pos + 1);
	float value = std::stof(value_str);
	for (const auto& pair : data.getDatabase()) {
		if (pair.first == line.substr(0, 10))
		{
			std::cout
			<< pair.first
			<< " => "
			<< pair.second
			<< " = "
			<< value * pair.second
			<< std::endl;
		}
	}
	//todo : previous date if not found
}

void	checkDateValidity( std::chrono::year_month_day& ymd ) {
	if (!ymd.ok()) {
		throw std::invalid_argument("Invalid date: " +
			std::to_string(static_cast<int>(ymd.year())) + "-" +
			std::to_string(static_cast<unsigned int>(ymd.month())) + "-" +
			std::to_string(static_cast<unsigned int>(ymd.day())));
	}
}

void	checkDateAndValueBounds( const BitcoinExchange& data, std::chrono::year_month_day& ymd, float value ) {
	if (value > 1000)
		throw std::runtime_error("Error: number too large");
	if (value < 0)
		throw std::runtime_error("Error: number too small");

	std::string first_date = data.getDatabase().begin()->first;

	int first_year = std::stoi(first_date.substr(0, 4));
	int first_month = std::stoi(first_date.substr(5, 2));
	int first_day = std::stoi(first_date.substr(8, 2));

	std::chrono::year_month_day first_ymd{
	std::chrono::year{first_year},
	std::chrono::month{static_cast<unsigned int>(first_month)},
	std::chrono::day{static_cast<unsigned int>(first_day)}
	};
	if (ymd < first_ymd)
		throw std::runtime_error("Error: date is before bitcoin existed");

	std::map<std::string, float>::iterator it = data.getDatabase().end();
	it--;
	std::string last_date = it->first;

	int last_year = std::stoi(last_date.substr(0, 4));
	int last_month = std::stoi(last_date.substr(5, 2));
	int last_day = std::stoi(last_date.substr(8, 2));

	std::chrono::year_month_day last_ymd{
	std::chrono::year{last_year},
	std::chrono::month{static_cast<unsigned int>(last_month)},
	std::chrono::day{static_cast<unsigned int>(last_day)}
	};
	if (ymd > last_ymd)
		throw std::runtime_error("Error: date is beyond database in future");
}

void	parseLine( std::string line, const BitcoinExchange& data ) {
	std::istringstream iss(line);
	int year;
	unsigned int month, day;
	char sep1, sep2, sep3, extra;
	float value;

	if (!(iss >> year >> sep1 >> month >> sep2 >> day >> sep3 >> value))
		throw std::runtime_error("Error: bad input => " + line);
	if (sep1 != '-' || sep2 != '-' || sep3 != '|')
		throw std::runtime_error("Error: bad input => " + line);
	if (iss >> extra)
		throw std::runtime_error("Error: bad input => " + line);

	std::chrono::year_month_day ymd{
	std::chrono::year{year},
	std::chrono::month{month},
	std::chrono::day{day}
	};

	checkDateValidity(ymd);
	checkDateAndValueBounds(data, ymd, value);
}

int	main(int ac, char **av)
{
	if (ac != 2) {
		std::cout << "Usage: ./btc <filename>" << std::endl;
		return 1;
	}
	(void)av;
	std::ifstream infile(av[1]);
	if (!infile.is_open()) {
		std::cout << "Error: could not open the file for reading" << std::endl;
		return 1;
	}

	BitcoinExchange database;

	// database.printDatabase();
	std::string line;
	while (1)
	{
		if(!std::getline(infile, line))
			break ;
		if (line == "date | value")
			continue ;
		try {
			parseLine(line, database);
			findKey(line, database);
		}
		catch (std::runtime_error& e) {
			std::cout << e.what() << std::endl;
		}
		catch (std::invalid_argument& e) {
			std::cout << e.what() << std::endl;
		}
	}
}
