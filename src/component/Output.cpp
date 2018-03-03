//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// 
//

#include <iostream>
#include "Exception.hpp"
#include "Database.hpp"
#include "component/Output.hpp"

namespace nts
{
	Output::Output(nts::Tristate state) : Component(), _set(false)
	{
		_state = state;
		_pins[1] = std::make_tuple(nts::PinType::INPUT, nullptr, 0);
	}
	
	nts::Tristate	Output::compute(std::size_t pin)
	{
		if (pin != 1)
			throw Exception("Output - " + std::to_string(pin) + 
			": not output available");
		else if (std::get<1>(_pins[1]) == nullptr)
			return (nts::Tristate::UNDEFINED);
		_state = std::get<1>(_pins[pin])->compute(std::get<2>(_pins[pin]));
		return (_state);
	}
}
