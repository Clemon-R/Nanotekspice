//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// 
//

#include <iostream>
#include "Database.hpp"
#include "component/Input.hpp"
#include "Exception.hpp"

namespace nts
{
	Input::Input(nts::Tristate state) : Component()
	{
		_state = state;
		_pins[1] = std::make_tuple(nts::PinType::OUTPUT, nullptr, 0);
	}
	
	nts::Tristate	Input::compute(std::size_t pin)
	{
		if (pin != 1)
			throw Exception("Input - " + std::to_string(pin) + 
					": not available output");
		return (_state);
	}

	void	Input::setValue(nts::Tristate state)
	{
		_state = state;
		Database::hasValue(*this);
	}
}
