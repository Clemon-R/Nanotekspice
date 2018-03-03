//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// 
//

#ifndef INPUT_HPP_
# define INPUT_HPP_

# include "Component.hpp"

namespace nts
{
	class Input : public Component
	{
	public:
		Input(nts::Tristate);
		nts::Tristate	compute(std::size_t) override;
		void	setValue(nts::Tristate);
	};
}
#endif
