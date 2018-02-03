//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// 
//

#include <iostream>
#include "Exception.hpp"
#include "Parser.hpp"
#include "component/Output.hpp"

namespace nts
{
	Output::Output(nts::Tristate state) : _state(state), _set(false)
	{
	}
	
	nts::Tristate	Output::compute(std::size_t pin)
	{
		if (pin != 1)
			throw Exception("Output - " + std::to_string(pin) + ": not output available");
		else if (!_set)
			throw Exception("Output - 1: not set");
		_state = std::get<0>(_link)->compute(std::get<1>(_link));
		dump();
		return (_state);
	}

	void	Output::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
	{
		if (pin != 1)
			throw Exception("Output - " + std::to_string(pin) + ": not available");
		_link = std::make_tuple(&other, otherPin);
		Parser::removeComponent(*static_cast<const nts::IComponent *>(this));
		Parser::removeComponent(other);
		_set = true;
	}

	void	Output::dump() const
	{
		std::cout << Parser::getNameByComponent(*static_cast<const nts::IComponent *>(this));
		if (_state == nts::Tristate::TRUE)
			std::cout << "=1";
		else if (_state == nts::Tristate::FALSE)
			std::cout << "=0";
		else
			std::cout << "=U";
		std::cout << std::endl;
	}
}
