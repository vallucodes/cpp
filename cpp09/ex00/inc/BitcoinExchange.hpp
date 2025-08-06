#include <iostream>
#include <map>

class Database {
	private:
		std::map<std::string, float>	data;

	public:
		Database( void ) = delete;
		Database( const Database& other ) = delete;
		Database& operator=( const Database& other ) = delete;
		~Database( void ) = delete;
		loadDatabase( std::string database );
}
