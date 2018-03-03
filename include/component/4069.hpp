/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** 
*/

#ifndef component4069_HPP_
# define component4069_HPP_

# include "Component.hpp"

namespace nts
{
    class component4069 : public Component
    {
    public:
		component4069();
		nts::Tristate	compute(std::size_t) override;
	private:
		nts::Tristate	invertState(nts::Tristate) const;
    };
}

#endif /* !4069_HPP_ */
