//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// 
//

#include <iostream>
#include "component/Input.hpp"

namespace nts
{
	Input::Input(nts::Tristate state) : _state(state)
	{
		std::cout << "Input was created\n";
	}
	
	nts::Tristate	Input::compute(std::size_t)
	{
	}

	void	Input::setLink(std::size_t, nts::IComponent &, std::size_t)
	{
	}

	void	Input::dump() const
	{
		if (_state == nts::Tristate::TRUE)
			std::cout << "1";
		else if (_state == nts::Tristate::FALSE)
			std::cout << "0";
		else
			std::cout << "U";
	}
}
