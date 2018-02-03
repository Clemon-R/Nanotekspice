//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// 
//

#ifndef component4071_HPP_
# define component4071_HPP_

# include "IComponent.hpp"
# include <iostream>
# include <map>
# include <tuple>

namespace nts
{
	class component4071 : public IComponent
	{
	public:
		component4071(nts::Tristate);
		nts::Tristate	compute(std::size_t) override;
		void	setLink(std::size_t, nts::IComponent &, std::size_t) override;
		void	dump() const override;
	private:
		Tristate	getState(std::tuple<IComponent *, std::size_t>, std::tuple<IComponent *, std::size_t>);
		
		std::map<std::size_t, std::tuple<IComponent *, std::size_t>>	_link;
		nts::Tristate	_state;
	};
}
#endif
