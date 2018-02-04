//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// 
//

#ifndef INPUT_HPP_
# define INPUT_HPP_

# include "IComponent.hpp"

namespace nts
{
	class Input : public IComponent
	{
	public:
		Input(nts::Tristate);
		nts::Tristate	compute(std::size_t) override;
		void	setLink(std::size_t, nts::IComponent &, std::size_t) override;
		void	dump() const override;
		void	setValue(nts::Tristate);
	private:
		nts::Tristate	_state;
	};
}
#endif
