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
		std::tuple<IComponent *, std::size_t>	comp1;
		std::tuple<IComponent *, std::size_t>	comp2;
		int	offset = 0;
		
		switch (pin)
		{
		case 3:
		case 11:
			offset = -1;
		        break;
		case 4:
	        case 10:
			offset = 1;
			break;
		default:
			throw Exception("4001 - " + std::to_string(pin) + ": is not a valid output");
			break;
		}
		if (_link.find(pin + 2 * offset) == _link.end() || _link.find(pin + offset) == _link.end())
			return (nts::Tristate::UNDEFINED);
		comp1 = _link[pin + 2 * offset];
		comp2 = _link[pin + offset];
		_state = getState(comp1, comp2);
		return (_state);		
	}

	void	fourGate::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
	{
		if (pin < 1 || pin > 14)
			throw Exception("4001 - " + std::to_string(pin) + ": not available");
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