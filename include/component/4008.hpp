/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** 
*/

#ifndef component4008_HPP_
# define component4008_HPP_

# include "Component.hpp"

namespace nts
{
    class component4008 : public Component
    {
    public:
		component4008();
		nts::Tristate	compute(std::size_t) override;
	private:
		nts::Tristate	getCout(nts::Tristate, nts::Tristate, nts::Tristate) const;
		nts::Tristate	getState(std::size_t);
		nts::Tristate	_cout;
    };
}

#endif /* !4008_HPP_ */
