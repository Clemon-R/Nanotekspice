//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// 
//

#include <iostream>
#include "Exception.hpp"
#include "Database.hpp"
#include "component/4071.hpp"

namespace nts
{
	component4071::component4071(nts::Tristate state) : _state(state)
	{
	}

	nts::Tristate	component4071::getState(std::tuple<IComponent *, std::size_t> comp1
						, std::tuple<IComponent *, std::size_t> comp2)
	{
		nts::Tristate	state1;
		nts::Tristate	state2;

		state1 = std::get<0>(comp1)->compute(std::get<1>(comp1));
		state2 = std::get<0>(comp2)->compute(std::get<1>(comp2));
		if (state1 == nts::Tristate::TRUE || state2 == nts::Tristate::TRUE)
			return (nts::Tristate::TRUE);
		else if (state1 == nts::Tristate::UNDEFINED || state2 == nts::Tristate::UNDEFINED)
			return (nts::Tristate::UNDEFINED);
		return (nts::Tristate::FALSE);
	}
	
	nts::Tristate	component4071::compute(std::size_t pin)
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
			throw Exception("4071 - " + std::to_string(pin) + ": is not a valid output");
			break;
		}
		if (_link.find(pin + 2 * offset) == _link.end() || _link.find(pin + offset) == _link.end())
			throw Exception("4071 - " + std::to_string(pin) + ": both input not set");
		comp1 = _link[pin + 2 * offset];
		comp2 = _link[pin + offset];
		_state = getState(comp1, comp2);
		return (_state);		
	}

	void	component4071::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
	{
		if (pin < 1 || pin > 14)
			throw Exception("4071 - " + std::to_string(pin) + ": not available");
		_link[pin] = std::make_tuple(&other, otherPin);
		Database::isLinked(*this);
		Database::isLinked(other);
	}

	void	component4071::dump() const
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
