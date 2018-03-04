/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** 
*/

#include "component/fourGate.hpp"
#include "Exception.hpp"
#include "Database.hpp"

namespace nts
{
	fourGate::fourGate(nts::Tristate state) : Component()
	{
		_state = state;
		for (std::size_t i = 1;i <= 14;i += 1)
			_pins[i] = std::make_tuple(nts::PinType::INPUT, nullptr, 0);
		std::get<0>(_pins[3]) = nts::PinType::OUTPUT;
		std::get<0>(_pins[4]) = nts::PinType::OUTPUT;
		std::get<0>(_pins[10]) = nts::PinType::OUTPUT;
		std::get<0>(_pins[11]) = nts::PinType::OUTPUT;
		std::get<0>(_pins[7]) = nts::PinType::USELESS;
		std::get<0>(_pins[14]) = nts::PinType::USELESS;
	}

	nts::Tristate	fourGate::compute(std::size_t pin)
	{
		int	offset = 0;
		nts::Tristate	state1;
		nts::Tristate	state2;

		if (_pins.find(pin) == _pins.end())
			throw Exception("FourGate - " + std::to_string(pin) + 
					": is not a valid output");
		else if (std::get<0>(_pins[pin]) != nts::PinType::OUTPUT)
			return (std::get<1>(_pins[pin]) == nullptr ? nts::Tristate::UNDEFINED :
			std::get<1>(_pins[pin])->compute(std::get<2>(_pins[pin])));
		offset = pin == 3 || pin == 10 ? -1 : 1;
		if ((std::get<0>(_pins[pin + offset * 2]) == nts::PinType::INPUT && 
				std::get<1>(_pins[pin + offset * 2]) == nullptr) || 
			(std::get<0>(_pins[pin + offset]) == nts::PinType::INPUT &&
				std::get<1>(_pins[pin + offset]) == nullptr))
			return (nts::Tristate::UNDEFINED);
		state1 = computeState(pin + offset * 2);
		state2 = computeState(pin + offset);
		_state = getState(state1, state2);
		return (_state);
	}
}
