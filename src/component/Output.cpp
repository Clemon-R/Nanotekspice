//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// 
//

#include <iostream>
#include "Parser.hpp"
#include "component/Output.hpp"

namespace nts
{
	Output::Output(nts::Tristate state) : _state(state)
	{
	}
	
	nts::Tristate	Output::compute(std::size_t pin)
	{
		_state = std::get<0>(_link[pin])->compute(std::get<1>(_link[pin]));
		dump();
		return (_state);
	}

	void	Output::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
	{
		_link[pin] = std::make_tuple(&other, otherPin);
		compute(pin);
	}

	void	Output::dump() const
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
