//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// 
//

#include <iostream>
#include "Database.hpp"
#include "component/Clock.hpp"
#include "Exception.hpp"

namespace nts
{
	Clock::Clock(nts::Tristate &state) : Input(state)
	{
	}
	
	nts::Tristate	Clock::compute(std::size_t pin)
	{
		nts::Tristate	current = _state;

		if (pin != 1)
			throw Exception("Input - " + std::to_string(pin) + 
					": not available output");
		if (_state == nts::Tristate::TRUE)
			_state = nts::Tristate::FALSE;
		else if (_state == nts::Tristate::FALSE)
			_state = nts::Tristate::TRUE;
		return (current);
	}
}
