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
	fourGate::fourGate(nts::Tristate state) : _state(state)
	{		
	}

	nts::Tristate	fourGate::compute(std::size_t pin)
	{
		int	offset = 0;

		if (pin < 1 || pin >= 14 || pin == 7)
			throw Exception("FourGate - " + std::to_string(pin) + 
					": is not a valid output");
		else if (pin != 3 && pin != 4 && pin != 10 && pin != 11)
			return (_link.find(pin) == _link.end() ? nts::Tristate::UNDEFINED :
			std::get<0>(_link[pin])->compute(std::get<1>(_link[pin])));
		offset = pin == 3 || pin == 11 ? -1 : 1;
		if (_link.find(pin + 2 * offset) == _link.end() || 
		_link.find(pin + offset) == _link.end())
			return (nts::Tristate::UNDEFINED);
		_state = getState(_link[pin + 2 * offset], _link[pin + offset]);
		return (_state);
	}

	void	fourGate::setLink(std::size_t pin, nts::IComponent &other, 
				  std::size_t otherPin)
	{
		if (pin < 1 || pin > 14)
			throw Exception("FourGate - " + std::to_string(pin) + 
					": not available");
		_link[pin] = std::make_tuple(&other, otherPin);
		Database::isLinked(*this);
		Database::isLinked(other);
	}

	void	fourGate::dump() const
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
