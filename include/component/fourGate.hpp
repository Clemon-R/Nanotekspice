/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** 
*/

#ifndef FOURGATE_HPP_
# define FOURGATE_HPP_

# include "Component.hpp"
# include "LogicBinary.hpp"
# include <map>

namespace nts
{
    class fourGate : public Component
    {
    public:
		fourGate(nts::Tristate);
		nts::Tristate	compute(std::size_t) override;
	protected:
		virtual Tristate	getState(nts::Tristate, nts::Tristate) = 0;
    };
}

#endif /* !FOURGATE_HPP_ */
