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
	nts::IComponent	*comp;
	std::string	arg;
	
	while (index < size)
	{
		arg = std::string(args[index]);
		pos = arg.find('=');
		if (pos == std::string::npos)
			throw Exception("Parameter: error syntax");
		comp = &Database::getComponentByName(arg.substr(0, pos));
		setInput(*static_cast<nts::Input *>(comp), arg.substr(pos + 1));
		index += 1;
	}
}

void	Parameter::setInput(nts::Input &comp, const std::string &value)
{
	nts::Tristate	kind = nts::Tristate::UNDEFINED;
	
	if (value == "1")
		kind = nts::Tristate::TRUE;
	else if (value == "0")
		kind = nts::Tristate::FALSE;
	comp.setValue(kind);
	Database::hasValue(comp);
}
