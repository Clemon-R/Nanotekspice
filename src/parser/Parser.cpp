//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// 
//

#include <fstream>
#include "Exception.hpp"
#include "Parser.hpp"
#include "ManagerComponent.hpp"

Parser::Parser(const std::string &file_name)
{
	std::string	line;
	std::ifstream	file(file_name);

	if (!file.is_open())
		throw Exception("Impossible to read the file");
	_step = "";
	while (getline(file, line))
		parseLine(line);
	file.close();
}

void	Parser::parseLine(const std::string &line)
{
	if (line.length() == 0 || line.at(0) == '#' || line.at(0) == '\n')
		return;

	if (line.at(0) == '.')
		_step = line;
	else{
		if (_step == ".chipsets:")
			parseChipsets(line);
		else if (_step == ".links:")
			parseLinks(line);
		else
			throw Exception("Incorrect step");
	}
}

void	Parser::parseChipsets(const std::string &line)
{
	std::size_t	pos = line.find(' ');
	std::size_t	pos_v = line.find('(');
	std::string	type;
	std::string	name;
	std::string	value = "";
	
	if (pos == std::string::npos)
		throw Exception("Error in chipsets");
	type = line.substr(0, pos);
	if (pos_v == std::string::npos)
		name = line.substr(pos + 1);
	else{
		name = line.substr(pos + 1, pos_v - pos - 1);
		value = line.substr(pos_v + 1, line.length() - pos_v - 2);
	}
	_list[name] = nts::ManagerComponent::createComponent(type, value);
}

void	Parser::parseLinks(const std::string &line)
{
}
