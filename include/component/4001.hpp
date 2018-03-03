//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// 
//

#ifndef component4001_HPP_
# define component4001_HPP_

# include "component/fourGate.hpp"

namespace nts
{
	class component4001 : public fourGate
	{
	public:
		component4001();
	private:
		Tristate	getState(nts::Tristate, nts::Tristate) override;
	};
}
#endif
