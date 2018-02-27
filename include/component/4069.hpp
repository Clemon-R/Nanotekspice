/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** 
*/

#ifndef component4069_HPP_
# define component4069_HPP_

# include "IComponent.hpp"
# include <map>

namespace nts
{
    class component4069 : public IComponent
    {
    public:
		component4069();
		nts::Tristate	compute(std::size_t) override;
		void	setLink(std::size_t, nts::IComponent &, std::size_t) override;
		void	dump() const override;
	private:
		nts::Tristate	invertState(nts::Tristate) const;
		std::map<std::size_t, std::tuple<IComponent *, std::size_t>>	_link;
		nts::Tristate	_state;
		nts::Tristate	_cout;
    };
}

#endif /* !4069_HPP_ */
