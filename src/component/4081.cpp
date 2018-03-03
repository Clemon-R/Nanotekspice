/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** 
*/

#include "component/4081.hpp"

namespace nts
{
	component4081::component4081() : nts::fourGate(nts::Tristate::UNDEFINED)
	{
	}

	nts::Tristate	component4081::getState(nts::Tristate state1, nts::Tristate state2)
	{
		return (LogicBinary::binaryAnd(state1, state2));
	}
}