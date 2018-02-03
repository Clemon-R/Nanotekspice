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

std::map<std::string, std::unique_ptr<nts::IComponent>>	Parser::_list;
std::list<nts::IComponent *>	Parser::_components;
std::map<std::string, nts::IComponent *>	Parser::_output;
std::string	Parser::_step;

void	Parser::parseFile(const std::string &file_name)
{
	std::string	line;
	std::ifstream	file(file_name);

	if (!file.is_open())
		throw Exception("Parser: impossible to open the given file");
	Parser::_step = "";
	while (getline(file, line))
		parseLine(line);
	file.close();
	checkSettings();
}

void	Parser::checkSettings()
{
	if (_components.size() > 0)
		throw Exception("Parser: all components are not linked - " + std::to_string(_components.size()));
}

nts::IComponent	&Parser::getComponentByName(const std::string &name)
{
        if (_list.find(name) == _list.end() || _list[name] == nullptr)
		throw Exception("Parser - " + name + ": component not found");
	return (*_list[name]);
}

const std::string	&Parser::getNameByComponent(const nts::IComponent &comp)
{
	for (const auto &elem : _list){
		if (&(*elem.second) == &comp){
			return (elem.first);
		}
	}
	throw Exception("Parser: impossible to find name of one component");
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
	else if (_list.find(name) != _list.end())
		throw Exception("Parser - " + name + ": double usage of this name");
	_list[name] = nts::ManagerComponent::createComponent(type, value);
	_components.push_back(&(*_list[name]));
	if (type == "output")
		_output[name] = &(*_list[name]);
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
		getComponentByName(comp2.substr(0, pos2)).setLink(
			std::stoi(comp2.substr(pos2 + 1)),
			getComponentByName(comp1.substr(0, pos1)),
			std::stoi(comp1.substr(pos1 + 1)));
	}
	catch (std::exception error){
		throw Exception("Parser: when linking");
	}
}

std::list<nts::IComponent *>	&Parser::getComponents()
{
	return (_components);
}

std::map<std::string, nts::IComponent *>	&Parser::getOutput()
{
	return (_output);
}

void	Parser::removeComponent(const nts::IComponent &comp)
{
	for (const auto &elem : _components){
		if (elem == &comp){
			_components.remove(elem);
			break;
		}
	}
}
