//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// 
//

#include <iostream>
#include "component/Output.hpp"

namespace nts
{
	Output::Output(nts::Tristate state) : _state(state)
	{
	}
	
	nts::Tristate	Output::compute(std::size_t)
	{
	}

	void	Output::setLink(std::size_t, nts::IComponent &, std::size_t)
	{
	}

	void	Output::dump() const
	{
		if (_state == nts::Tristate::TRUE)
			std::cout << "1";
		else if (_state == nts::Tristate::FALSE)
			std::cout << "0";
		else
			std::cout << "U";
	}
}
