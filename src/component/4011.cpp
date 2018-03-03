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
	
	nts::Tristate	component4011::getState(nts::Tristate state1, nts::Tristate state2)
	{
		return (LogicBinary::binaryNand(state1, state2));
	}
}
