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
	component4008::component4008() : _state(nts::Tristate::UNDEFINED)
				       , _cout(nts::Tristate::UNDEFINED)
	{
		
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
		
		cin = std::get<0>(_link[9])->compute(std::get<1>(_link[9]));
		for (std::size_t i = 0;i <= pin - 10;i += 1){
			ia = i == 3 ? 1 : 7 - i * 2;
			ib = i == 3 ? 15 : 7 - i * 2 - 1;
			if (_link.find(ia) == _link.end() || 
			    _link.find(ib) == _link.end())
				return (nts::Tristate::UNDEFINED);
			a = std::get<0>(_link[ia])->compute(std::get<1>(_link[ia]));
			b = std::get<0>(_link[ib])->compute(std::get<1>(_link[ib]));
			sum = LogicBinary::binaryXor(LogicBinary::binaryXor(a, b), cin);
			_cout = getCout(a, b, cin);
		}
		return (sum);
	}

	nts::Tristate	component4008::compute(std::size_t pin)
	{
		if (pin < 1 || pin > 16 || pin == 8 || pin == 16)
			throw Exception("4008 - " + std::to_string(pin) 
					+ ": is not a valid output");
		else if (_link.find(pin) == _link.end())
			return (nts::Tristate::UNDEFINED);
		else if (pin == 14)
			return (_cout);
		_state = getState(pin);
		return (_state);	
	}

	void	component4008::setLink(std::size_t pin, nts::IComponent &other
				       , std::size_t otherPin)
	{
		if (pin == 8 || (pin >= 10 && pin <= 14) || pin == 16 
			|| pin < 1 || pin > 16)
			throw Exception("4008 - "+ std::to_string(pin) +": not available");
		_link[pin] = std::make_tuple(&other, otherPin);
		Database::isLinked(*this);
		Database::isLinked(other);
	}
	
	void	component4008::dump() const
	{
		std::cout << Database::getNameByComponent(*this);
		if (_state == nts::Tristate::TRUE)
			std::cout << "=1";
		else if (_state == nts::Tristate::FALSE)
			std::cout << "=0";
		else
			std::cout << "=U";
		std::cout << std::endl;
	}
}
