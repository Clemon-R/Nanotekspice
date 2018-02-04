//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// 
//

#ifndef PARAMETER_HPP_
# define PARAMETER_HPP_

# include "IComponent.hpp"
# include "component/Input.hpp"

class Parameter
{
public:
	static void	parseParams(int, int, char **);
	static void	setInput(nts::Input &, const std::string &);
};

#endif
