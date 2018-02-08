/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** 
*/

#ifndef FOURGATE_HPP_
# define FOURGATE_HPP_

# include "IComponent.hpp"
# include <map>

namespace nts
{
    class fourGate : public IComponent
    {
    public:
		fourGate(nts::Tristate);
		nts::Tristate	compute(std::size_t) override;
		void	setLink(std::size_t, nts::IComponent &, std::size_t) override;
		void	dump() const override;
	protected:
		virtual Tristate	getState(std::tuple<IComponent *, std::size_t>, std::tuple<IComponent *, std::size_t>) = 0;

		std::map<std::size_t, std::tuple<IComponent *, std::size_t>>	_link;
		nts::Tristate	_state;
    };
}

#endif /* !FOURGATE_HPP_ */
