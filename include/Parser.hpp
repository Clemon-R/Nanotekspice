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
# include <list>
# include <memory>
# include "IComponent.hpp"

class Parser
{
public:
	static void	parseFile(const std::string &);

	static nts::IComponent	&getComponentByName(const std::string &);
	static const std::string	&getNameByComponent(const nts::IComponent &);

	static std::list<nts::IComponent *>	&getComponents();
	static std::map<std::string, nts::IComponent *>	&getOutput();

	static void	removeComponent(const nts::IComponent &);
private:
	static void	parseLine(const std::string &);
	static void	parseChipsets(const std::string &);
	static void	parseLinks(const std::string &);

	static void	setLink(const std::string &, const std::string &);
	static void	checkSettings();

	static std::map<std::string, std::unique_ptr<nts::IComponent>> _list;
	static std::list<nts::IComponent *>	_components;
	static std::map<std::string, nts::IComponent *>	_output;
        static std::string	_step;
};
#endif
