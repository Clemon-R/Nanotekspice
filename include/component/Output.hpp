//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// 
//

#pragma once

#include "IComponent.hpp"
#include <iostream>
#include <map>

namespace nts
{
	class Output : public IComponent
	{
	public:
		Output(nts::Tristate);
		nts::Tristate	compute(std::size_t) override;
		void	setLink(std::size_t, nts::IComponent &, std::size_t) override;
		void	dump() const override;
	private:
		std::map<std::size_t, nts::IComponent &>	_link;
		nts::Tristate	_state;
	};
}
