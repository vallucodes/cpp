#include <iostream>

std::string	replace_content(std::string line, std::string replace, std::string replacer) {
	if (replace.empty())
		return (line);

	size_t	pos = 0;
	while (1)
	{
		pos = line.find(replace, pos);
		if (pos == std::string::npos)
			break ;
		line.erase(pos, replace.length());
		line.insert(pos, replacer);
		pos += replacer.length();
	}
	return (line);
}
