//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// 
//

#ifndef FALSE_HPP_
# define FALSE_HPP_

# include "IComponent.hpp"

namespace nts
{
	class False : public IComponent
	{
	public:
		False();
		nts::Tristate	compute(std::size_t) override;
		void	setLink(std::size_t, nts::IComponent &, std::size_t) override;
		void	dump() const override;
	private:
		nts::Tristate	_state;
	};
}
#endif
