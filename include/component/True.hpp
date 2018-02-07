//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// 
//

#ifndef TRUE_HPP_
# define TRUE_HPP_

# include "IComponent.hpp"

namespace nts
{
	class True : public IComponent
	{
	public:
		True();
		nts::Tristate	compute(std::size_t) override;
		void	setLink(std::size_t, nts::IComponent &, std::size_t) override;
		void	dump() const override;
	private:
		nts::Tristate	_state;
	};
}
#endif
