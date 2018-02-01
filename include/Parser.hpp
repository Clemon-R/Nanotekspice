//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// 
//

#pragma once

#include <iostream>
#include <map>
#include <memory>
#include "IComponent.hpp"

class Parser
{
public:
	Parser(const std::string &);
private:
	void	parseLine(const std::string &);
	void	parseChipsets(const std::string &);
	void	parseLinks(const std::string &);

	std::map<std::string, std::unique_ptr<nts::IComponent>> _list;
        std::string	_step;
};
