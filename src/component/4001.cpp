//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// 
//

#include <iostream>
#include "Exception.hpp"
#include "Database.hpp"
#include "component/4001.hpp"

namespace nts
{
	component4001::component4001() : nts::fourGate(nts::Tristate::UNDEFINED)
	{
	}

	nts::Tristate	component4001::getState(nts::Tristate state1, nts::Tristate state2)
	{
		return (LogicBinary::binaryNor(state1, state2));
	}
}
