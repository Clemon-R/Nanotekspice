//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// 
//

#include <fstream>
#include <algorithm>
#include "Exception.hpp"
#include "Parser.hpp"
#include "ManagerComponent.hpp"
#include "Database.hpp"

std::string	Parser::_step;

void	Parser::parseFile(const std::string &file_name)
{
	std::string	line;
	std::ifstream	file(file_name);
	std::size_t	ret;

	if (!file.is_open())
		throw Exception("Parser: impossible to open the given file");
	Parser::_step = "";
	while (getline(file, line)){
		std::replace(line.begin(), line.end(), '\t', ' ');
		ret = line.find('\r');
		if (ret != std::string::npos)
			line.erase(ret);
		parseLine(line);
	}
	file.close();
}

void	Parser::checkSettings()
{
	for (const auto &elem : Database::getComponents()){
		if (std::get<2>(elem.second) == false)
			throw Exception("Parser - " + std::get<1>(elem.second) \
					+ ": is not linked");
		else if (std::get<3>(elem.second) == false)
			throw Exception("Parser - " + std::get<1>(elem.second) \
					+ ": is not set");
	}
}

void	Parser::parseLine(const std::string &line)
{
	if (line.length() == 0 || line.at(0) == '#' || line.at(0) == '\n')
		return;

	if (line.at(0) == '.'){
		if ((_step == ".chipsets:" && line != ".links:") ||
		    (_step != ".chipsets:" && line == ".links:") ||
		    (line != ".chipsets:" && line != ".links:"))
			throw Exception("Parser - " + line + ": not the right time or unknown");
		_step = line;
	}
	else{
		if (_step == ".chipsets:")
			parseChipsets(line);
		else if (_step == ".links:")
			parseLinks(line);;
	}
}

void	Parser::parseChipsets(const std::string &line)
{
	std::size_t	pos = line.find(' ');
	std::size_t	pos_v = line.find('(');
	std::string	type;
	std::string	name = "";
	std::string	value = "";
	nts::IComponent	*comp;
	
	if (pos == std::string::npos)
		throw Exception("Parser: name not found");
	type = line.substr(0, pos);
	if (pos_v == std::string::npos)
		name = line.substr(pos + 1);
	else{
		name = line.substr(pos + 1, pos_v - pos - 1);
		value = line.substr(pos_v + 1, line.length() - pos_v - 2);
	}
	if (name == "")
		throw Exception("Parser: name not found");
	comp = &Database::addComponent(nts::ManagerComponent::createComponent(type, value), name, type);
	if (value != "")
		Database::hasValue(*comp);
}

void	Parser::parseLinks(const std::string &line)
{
	std::size_t	pos = line.find(' ');
	std::string	elem1;
	std::string	elem2;

	if (pos == std::string::npos)
		throw Exception("Parser: one line doesn't contains target");
	elem1 = line.substr(0, pos);
	elem2 = line.substr(pos + 1);
	setLink(elem1, elem2);
}

void	Parser::setLink(const std::string &comp1, const std::string &comp2)
{
	std::size_t	pos1 = comp1.find(':');
	std::size_t	pos2 = comp2.find(':');
	
	if (pos1 == std::string::npos || pos2 == std::string::npos)
		throw Exception("Parser: one line doesn't contains pin");
	try{
		Database::getComponentByName(comp2.substr(0, pos2)).setLink(
			std::stoi(comp2.substr(pos2 + 1)),
			Database::getComponentByName(comp1.substr(0, pos1)),
			std::stoi(comp1.substr(pos1 + 1)));
	}
	catch (std::exception &error){
		throw Exception("Parser: when linking");
	}
}
