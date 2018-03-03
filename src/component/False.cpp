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
	False::False() : Component()
	{
		_state = nts::Tristate::FALSE;
		_pins[1] = std::make_tuple(nts::PinType::OUTPUT, nullptr, 0);
	}
	
	nts::Tristate	False::compute(std::size_t pin)
	{
		if (pin != 1)
			throw Exception("False - " + std::to_string(pin) + 
					": not available output");
		return (_state);
	}
}
