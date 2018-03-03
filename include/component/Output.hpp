//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// 
//

#ifndef OUTPUT_HPP_
# define OUTPUT_HPP_

# include "Component.hpp"

namespace nts
{
	class Output : public Component
	{
	public:
		Output(nts::Tristate);
		nts::Tristate	compute(std::size_t) override;
	private:
		bool		_set;
	};
}
#endif
