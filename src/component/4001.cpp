//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// 
//

#include <iostream>
#include "Exception.hpp"
#include "Parser.hpp"
#include "component/4001.hpp"

namespace nts
{
	component4001::component4001(nts::Tristate state) : _state(state)
	{
	}

	nts::Tristate	component4001::getState(std::tuple<IComponent *, std::size_t> comp1
						, std::tuple<IComponent *, std::size_t> comp2)
	{
		nts::Tristate	state1;
		nts::Tristate	state2;

		state1 = std::get<0>(comp1)->compute(std::get<1>(comp1));
		state2 = std::get<0>(comp2)->compute(std::get<1>(comp2));
		if (state1 == nts::Tristate::TRUE || state2 == nts::Tristate::TRUE)
			return (nts::Tristate::FALSE);
		else if (state1 == nts::Tristate::UNDEFINED || state2 == nts::Tristate::UNDEFINED)
			return (nts::Tristate::FALSE);
		return (nts::Tristate::TRUE);
	}
	
	nts::Tristate	component4001::compute(std::size_t pin)
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
			throw Exception("Error compute wrong pin");
			break;
		}
		comp1 = _link[pin + 2 * offset];
		comp2 = _link[pin + offset];
		_state = getState(comp1, comp2);
		return (_state);		
	}

	void	component4001::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
	{
		if (pin < 1 || pin > 14)
			throw Exception("Pin not found");
		_link[pin] = std::make_tuple(&other, otherPin);
		other.compute(otherPin);
	}

	void	component4001::dump() const
	{
		std::cout << Parser::getNameByComponent(*static_cast<const nts::IComponent *>(this));
		if (_state == nts::Tristate::TRUE)
			std::cout << "=1";
		else if (_state == nts::Tristate::FALSE)
			std::cout << "=0";
		else
			std::cout << "=U";
		std::cout << std::endl;
	}
}
