//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// 
//

#include <iostream>
#include "Parameter.hpp"
#include "Exception.hpp"
#include "Database.hpp"
#include "component/Input.hpp"

void	Parameter::parseParams(int index, int size, char **args)
{
	std::size_t	pos;
	std::string	arg;
	
	while (index < size)
	{
		arg = std::string(args[index]);
		pos = arg.find('=');
		if (pos == std::string::npos)
			throw Exception("Parameter: error syntax");
		parseInput(arg.substr(0, pos), arg.substr(pos + 1));
		index += 1;
	}
}

void	Parameter::parseInput(const std::string &input, const std::string &value)
{
	for (const auto &elem : Database::getComponents()){
		if (std::get<1>(elem.second) != input)
			continue;
		if (std::get<0>(elem.second) <= Database::Type::CLOCK){
			setInput(static_cast<nts::Input &>(*elem.first), value);
			return;
		}
	}
	throw Exception("Parameter - " + input + ": input not found");
}

void	Parameter::setInput(nts::Input &comp, const std::string &value)
{
	nts::Tristate	kind = nts::Tristate::UNDEFINED;
	
	if (value == "1")
		kind = nts::Tristate::TRUE;
	else if (value == "0")
		kind = nts::Tristate::FALSE;
	comp.setValue(kind);
}
