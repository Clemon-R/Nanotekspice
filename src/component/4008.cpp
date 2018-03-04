/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** 
*/

#include "component/4008.hpp"
#include "Exception.hpp"
#include "Database.hpp"
#include "LogicBinary.hpp"

namespace nts
{
	component4008::component4008() : Component(), _cout(nts::Tristate::UNDEFINED)
	{
		for (std::size_t i = 1;i <= 16;i += 1)
			_pins[i] = std::make_tuple(nts::PinType::INPUT, nullptr, 0);
		std::get<0>(_pins[10]) = nts::PinType::OUTPUT;
		std::get<0>(_pins[11]) = nts::PinType::OUTPUT;
		std::get<0>(_pins[12]) = nts::PinType::OUTPUT;
		std::get<0>(_pins[13]) = nts::PinType::OUTPUT;
		std::get<0>(_pins[14]) = nts::PinType::OUTPUT;
		std::get<0>(_pins[8]) = nts::PinType::USELESS;
		std::get<0>(_pins[16]) = nts::PinType::USELESS;
	}
	
	nts::Tristate	component4008::getCout(nts::Tristate a,
                                            nts::Tristate b,
					       nts::Tristate cin) const
	{
		nts::Tristate   result1 = LogicBinary::binaryAnd(a, b);
		nts::Tristate   result2;
		
		result2 = LogicBinary::binaryXor(
			LogicBinary::binaryAnd(a, cin), 
			LogicBinary::binaryAnd(b, cin));        
		return (LogicBinary::binaryOr(result1, result2));
	}
	
	nts::Tristate	component4008::getState(std::size_t pin)
	{
		nts::Tristate	cin = nts::Tristate::UNDEFINED;
		nts::Tristate	a;
		nts::Tristate	b;
		nts::Tristate	sum = nts::Tristate::UNDEFINED;
		std::size_t	ia;
		std::size_t	ib;
		
		cin = std::get<1>(_pins[9])->compute(std::get<2>(_pins[9]));
		for (std::size_t i = 0;i <= pin - 10;i += 1){
			ia = i == 3 ? 1 : 7 - i * 2;
			ib = i == 3 ? 15 : 7 - i * 2 - 1;
			if ((std::get<0>(_pins[ia]) == nts::PinType::INPUT &&
				std::get<1>(_pins[ia]) == nullptr) || 
			    (std::get<0>(_pins[ib]) == nts::PinType::INPUT &&
				std::get<1>(_pins[ib]) == nullptr))
				return (nts::Tristate::UNDEFINED);
			a = std::get<1>(_pins[ia])->compute(std::get<2>(_pins[ia]));
			b = std::get<1>(_pins[ib])->compute(std::get<2>(_pins[ib]));
			sum = LogicBinary::binaryXor(LogicBinary::binaryXor(a, b), cin);
			_cout = getCout(a, b, cin);
		}
		return (sum);
	}

	nts::Tristate	component4008::compute(std::size_t pin)
	{
		if (_pins.find(pin) == _pins.end())
			throw Exception("4008 - " + std::to_string(pin) 
					+ ": is not a valid output");
		else if (std::get<0>(_pins[pin]) != nts::PinType::OUTPUT)
			return (std::get<1>(_pins[pin]) == nullptr ?
			nts::Tristate::UNDEFINED : computeState(pin));
		else if (pin == 14)
			return (_cout);
		_state = getState(pin);
		return (_state);	
	}
}
