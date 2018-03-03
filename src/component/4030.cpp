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
	
	nts::Tristate	component4030::getState(nts::Tristate state1, nts::Tristate state2)
	{
		return (LogicBinary::binaryXor(state1, state2));
	}
}
