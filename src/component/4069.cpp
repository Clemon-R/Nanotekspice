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
	component4069::component4069() : _state(nts::Tristate::UNDEFINED)
	{
		
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

		if (pin == 7 || pin >= 14 || pin < 1)
			throw Exception("4069 - "+ std::to_string(pin) +": not available");
		else if (pin % 2 == 1)
			return (_link.find(pin) == _link.end() ? nts::Tristate::UNDEFINED :
			std::get<0>(_link[pin])->compute(std::get<1>(_link[pin])));
		offset = pin == 2 || pin == 4 || pin == 6 ? -1 : 1;
		if (_link.find(pin + offset) == _link.end())
			return (nts::Tristate::UNDEFINED);
		_state = invertState(std::get<0>(_link[pin + offset])->compute(
					     std::get<1>(_link[pin + offset])));
		return (_state);	
	}

	void	component4069::setLink(std::size_t pin, nts::IComponent &other
				       , std::size_t otherPin)
	{
		if (pin > 14 || pin < 1)
			throw Exception("4069 - "+ std::to_string(pin) +": not available");
		_link[pin] = std::make_tuple(&other, otherPin);
		Database::isLinked(*this);
		Database::isLinked(other);
	}
	
	void	component4069::dump() const
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
