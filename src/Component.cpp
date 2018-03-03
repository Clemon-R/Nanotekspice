/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** Component
*/

#include "Component.hpp"
#include "Exception.hpp"
#include "Database.hpp"

namespace nts
{
    Component::Component() : _state(nts::Tristate::UNDEFINED)
    {
    }
    
    void	Component::setLink(std::size_t pin, nts::IComponent &other, 
				  std::size_t otherPin)
	{
		if (_pins.find(pin) == _pins.end())
			throw Exception("Component - " + std::to_string(pin) +
					": not available");
        std::get<1>(_pins[pin]) = &other;
        std::get<2>(_pins[pin]) = otherPin;
		Database::isLinked(*this);
		Database::isLinked(other);
	}

	void	Component::dump() const
	{
		std::cout << _name;
		if (_state == nts::Tristate::TRUE)
			std::cout << "=1";
		else if (_state == nts::Tristate::FALSE)
			std::cout << "=0";
		else
			std::cout << "=U";
		std::cout << std::endl;
	}

	void	Component::setName(const std::string &name)
	{
		_name = name;
	}

	const std::string	&Component::getName() const
	{
		return (_name);
	}

	nts::PinType	Component::getType(std::size_t pin)
	{
		return (std::get<0>(_pins[pin]));
	}
}