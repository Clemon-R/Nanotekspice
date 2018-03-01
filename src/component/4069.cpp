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
		int	offset = 0;
		switch (pin){
		case 2:
		case 4:
		case 6:
			offset = -1;
			break;
		case 12:
		case 10:
		case 8:
			offset = 1;
			break;
		default:
			throw Exception("4069 - " + std::to_string(pin)
					+ ": is not a valid output");
		}
		if (_link.find(pin + offset) == _link.end())
			throw Exception("4069 - " + std::to_string(pin) + ": pin not found");
		_state = invertState(std::get<0>(_link[pin + offset])->compute(
					     std::get<1>(_link[pin + offset])));
		return (_state);	
	}

	void	component4069::setLink(std::size_t pin, nts::IComponent &other
				       , std::size_t otherPin)
	{
		if (pin == 8 || (pin >= 10 && pin <= 13) || pin == 16)
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
