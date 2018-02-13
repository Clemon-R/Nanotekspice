/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** 
*/

#ifndef component4030_HPP_
# define component4030_HPP_

# include "component/fourGate.hpp"

namespace nts
{
    class component4030 : public fourGate
    {
    public:
        component4030();
    private:
		Tristate	getState(std::tuple<IComponent *, std::size_t>, std::tuple<IComponent *, std::size_t>) override;
    };
}

#endif /* !4030_HPP_ */
