//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// 
//

#include <iostream>
#include "Database.hpp"
#include "component/False.hpp"
#include "Exception.hpp"

namespace nts
{
	False::False() : _state(nts::Tristate::FALSE)
	{
	}
	
	nts::Tristate	False::compute(std::size_t pin)
	{
		if (pin != 1)
			throw Exception("False - " + std::to_string(pin) + 
			": not available output");
		return (_state);
	}

	void	False::setLink(std::size_t pin, nts::IComponent &, std::size_t)
	{
		throw Exception("False - " + std::to_string(pin) + ": not available");
	}

	void	False::dump() const
	{
		std::cout << Database::getNameByComponent(*this);
		if (_state == nts::Tristate::TRUE)
			std::cout << "=1";
		else if (_state == nts::Tristate::FALSE)
			std::cout << "=0";
		else
			std::cout << "=U";
		std::cout << std::endl;		
	}
}
