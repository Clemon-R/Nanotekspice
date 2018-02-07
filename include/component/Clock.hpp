//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// 
//

#ifndef CLOCK_HPP_
# define CLOCK_HPP_

# include "component/Input.hpp"

namespace nts
{
	class Clock : public Input
	{
	public:
		Clock(nts::Tristate &);
		nts::Tristate	compute(std::size_t) override;
	};
}
#endif
