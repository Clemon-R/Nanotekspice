//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// 
//

#ifndef component4071_HPP_
# define component4071_HPP_

# include "component/fourGate.hpp"

namespace nts
{
	class component4071 : public fourGate
	{
	public:
		component4071();
	private:
		Tristate	getState(std::tuple<IComponent *, std::size_t>, std::tuple<IComponent *, std::size_t>) override;
	};
}
#endif
