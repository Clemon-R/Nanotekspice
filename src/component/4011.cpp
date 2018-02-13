/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** 
*/

#include "component/4011.hpp"

namespace nts
{
    component4011::component4011() : nts::fourGate(nts::Tristate::UNDEFINED)
    {        
    }

    nts::Tristate	component4011::getState(std::tuple<IComponent *, std::size_t> comp1
						, std::tuple<IComponent *, std::size_t> comp2)
	{
		nts::Tristate	state1;
		nts::Tristate	state2;

		state1 = std::get<0>(comp1)->compute(std::get<1>(comp1));
		state2 = std::get<0>(comp2)->compute(std::get<1>(comp2));
		if (state1 == nts::Tristate::TRUE && state2 == nts::Tristate::TRUE)
			return (nts::Tristate::FALSE);
		else if (state1 == nts::Tristate::UNDEFINED || state2 == nts::Tristate::UNDEFINED)
			return (nts::Tristate::UNDEFINED);
		return (nts::Tristate::TRUE);
	}
}