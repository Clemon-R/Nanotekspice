//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// 
//

#ifndef TRUE_HPP_
# define TRUE_HPP_

# include "Component.hpp"

namespace nts
{
	class True : public Component
	{
	public:
		True();
		nts::Tristate	compute(std::size_t) override;
	};
}
#endif
