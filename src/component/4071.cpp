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
	component4071::component4071() : nts::fourGate(nts::Tristate::UNDEFINED)
	{
	}

	nts::Tristate	component4071::getState(nts::Tristate state1, nts::Tristate state2)
	{
		return (LogicBinary::binaryOr(state1, state2));
	}
}
