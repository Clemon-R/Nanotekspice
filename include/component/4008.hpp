/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** 
*/

#ifndef component4008_HPP_
# define component4008_HPP_

# include "IComponent.hpp"
# include <map>

namespace nts
{
    class component4008 : public IComponent
    {
    public:
		component4008();
		nts::Tristate	compute(std::size_t) override;
		void	setLink(std::size_t, nts::IComponent &, std::size_t) override;
		void	dump() const override;
	private:
		nts::Tristate	getCout(nts::Tristate, nts::Tristate, nts::Tristate) const;
		nts::Tristate	getState(std::size_t);
		std::map<std::size_t, std::tuple<IComponent *, std::size_t>>	_link;
		nts::Tristate	_state;
		nts::Tristate	_cout;
    };
}

#endif /* !4008_HPP_ */
