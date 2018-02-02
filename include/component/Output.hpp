//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// 
//

#ifndef OUTPUT_HPP_
# define OUTPUT_HPP_

# include "IComponent.hpp"
# include <iostream>
# include <map>
# include <tuple>

namespace nts
{
	class Output : public IComponent
	{
	public:
		Output(nts::Tristate);
		nts::Tristate	compute(std::size_t) override;
		void	setLink(std::size_t, nts::IComponent &, std::size_t) override;
		void	dump() const override;
	private:
		std::tuple<nts::IComponent *, std::size_t>	_link;
		nts::Tristate	_state;
	};
}
#endif
