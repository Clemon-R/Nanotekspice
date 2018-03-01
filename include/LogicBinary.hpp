/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** 
*/

#ifndef LOGICBINARY_HPP_
# define LOGICBINARY_HPP_

# include "IComponent.hpp"

class LogicBinary
{
public:
	static nts::Tristate	binaryXor(nts::Tristate, nts::Tristate);
	static nts::Tristate	binaryOr(nts::Tristate, nts::Tristate);
	static nts::Tristate	binaryNor(nts::Tristate, nts::Tristate);
	static nts::Tristate	binaryAnd(nts::Tristate, nts::Tristate);
	static nts::Tristate	binaryNand(nts::Tristate, nts::Tristate);
};

#endif /* !LOGICBINARY_HPP_ */
