//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// 
//

#include <iostream>
#include "Database.hpp"
#include "component/True.hpp"
#include "Exception.hpp"

namespace nts
{
	True::True() : Component()
	{
		_state = nts::Tristate::TRUE;
		_pins[1] = std::make_tuple(nts::PinType::OUTPUT, nullptr, 0);
	}
	
	nts::Tristate	True::compute(std::size_t pin)
	{
		if (pin != 1)
			throw Exception("True - " + std::to_string(pin) + 
					": not available output");
		return (_state);
	}
}
