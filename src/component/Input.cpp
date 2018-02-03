//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// 
//

#include <iostream>
#include "Parser.hpp"
#include "component/Input.hpp"
#include "Exception.hpp"

namespace nts
{
	Input::Input(nts::Tristate state) : _state(state)
	{
	}
	
	nts::Tristate	Input::compute(std::size_t pin)
	{
		if (pin != 1)
			throw Exception("Input - " + std::to_string(pin) + ": not available output");
		return (_state);
	}

	void	Input::setLink(std::size_t pin, nts::IComponent &, std::size_t)
	{
		throw Exception("Input - " + std::to_string(pin) + ": not available");
	}

	void	Input::dump() const
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
