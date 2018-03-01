//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// 
//

#ifndef PARSER_HPP_
# define PARSER_HPP_

# include <iostream>
# include <map>
# include <tuple>
# include <memory>
# include "IComponent.hpp"

class Parser
{
public:
	static void	parseFile(const std::string &);
	static void	checkSettings();
private:
	static void	parseLine(const std::string &);
	static void	parseChipsets(const std::string &);
	static void	parseLinks(const std::string &);
	static void	setLink(const std::string &, const std::string &);
        static std::string	_step;
};
#endif
