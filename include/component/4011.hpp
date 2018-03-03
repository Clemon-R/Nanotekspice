/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** 
*/

#ifndef COMPONENT4011_HPP_
# define COMPONENT4011_HPP_

# include "component/fourGate.hpp"

namespace nts
{
    class component4011 : public fourGate
    {
    public:
        component4011();
    private:
		Tristate	getState(nts::Tristate, nts::Tristate) override;
    };
}
#endif /* !4011_HPP_ */
