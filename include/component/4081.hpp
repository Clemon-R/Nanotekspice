/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** 
*/

#ifndef component4081_HPP_
# define component4081_HPP_

# include "fourGate.hpp"

namespace nts
{
	class component4081 : public fourGate
	{
	public:
		component4081();
	private:
		Tristate	getState(std::tuple<IComponent *, std::size_t>, std::tuple<IComponent *, std::size_t>) override;
	};
}
#endif /* !4087_HPP_ */
