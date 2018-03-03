//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// 
//

#ifndef FALSE_HPP_
# define FALSE_HPP_

# include "Component.hpp"

namespace nts
{
	class False : public Component
	{
	public:
		False();
		nts::Tristate	compute(std::size_t) override;
	};
}
#endif
