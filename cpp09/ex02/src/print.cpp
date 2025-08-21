#include "print.hpp"

void	print_map( std::vector<int>& keys, std::unordered_map<int, int>& pairs, int level) {
	std::cout << "level " << level << std::endl;
	for (size_t i = 0; i < keys.size(); ++i)
	{
		auto it = pairs.find(keys[i]);
		if (it != pairs.end())
		{
			int value = it->second;
			std::cout << "key: " << keys[i] << " value: " << value << std::endl;
		}
		else
			std::cout << "key: " << keys[i] << " value: " << "not found in map" << std::endl;
	}
}
