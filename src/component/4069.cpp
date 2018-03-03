/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** 
*/

#include "component/4069.hpp"
#include "Exception.hpp"
#include "Database.hpp"
#include "LogicBinary.hpp"

namespace nts
{
	component4069::component4069() : Component()
	{
		for (std::size_t i = 1;i <= 14;i += 1)
			_pins[i] = std::make_tuple(nts::PinType::INPUT, nullptr, 0);
		std::get<0>(_pins[2]) = nts::PinType::OUTPUT;
		std::get<0>(_pins[4]) = nts::PinType::OUTPUT;
		std::get<0>(_pins[6]) = nts::PinType::OUTPUT;
		std::get<0>(_pins[8]) = nts::PinType::OUTPUT;
		std::get<0>(_pins[10]) = nts::PinType::OUTPUT;
		std::get<0>(_pins[12]) = nts::PinType::OUTPUT;
		std::get<0>(_pins[7]) = nts::PinType::USELESS;
		std::get<0>(_pins[14]) = nts::PinType::USELESS;
	}
	
	nts::Tristate   component4069::invertState(nts::Tristate state) const
	{
		if (state == nts::Tristate::TRUE)
			return (nts::Tristate::FALSE);
		else if (state == nts::Tristate::FALSE)
			return (nts::Tristate::TRUE);
		return (nts::Tristate::UNDEFINED);
	}
	
	nts::Tristate	component4069::compute(std::size_t pin)
	{
		int	offset = -1;

		if (_pins.find(pin) == _pins.end())
			throw Exception("4069 - "+ std::to_string(pin) +": not available");
		else if (pin % 2 == 1)
			return (std::get<1>(_pins[pin]) == nullptr ? nts::Tristate::UNDEFINED :
			std::get<1>(_pins[pin])->compute(std::get<2>(_pins[pin])));
		offset = pin == 2 || pin == 4 || pin == 6 ? -1 : 1;
		if (std::get<1>(_pins[pin]) == nullptr)
			return (nts::Tristate::UNDEFINED);
		_state = invertState(std::get<1>(_pins[pin + offset])->compute(
					     std::get<2>(_pins[pin + offset])));
		return (_state);	
	}
}
