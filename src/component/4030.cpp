/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** 
*/

#include "component/4030.hpp"

namespace nts
{
    component4030::component4030() : nts::fourGate(nts::Tristate::UNDEFINED)
    {
    }

    nts::Tristate	component4030::getState(std::tuple<IComponent *, 
						std::size_t> comp1, std::tuple<IComponent *, 
						std::size_t> comp2)
	{
		nts::Tristate	state1;
		nts::Tristate	state2;

		state1 = std::get<0>(comp1)->compute(std::get<1>(comp1));
		state2 = std::get<0>(comp2)->compute(std::get<1>(comp2));
		return (LogicBinary::binaryXor(state1, state2));
	}
}