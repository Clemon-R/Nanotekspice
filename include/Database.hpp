//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// 
//

#ifndef DATABASE_HPP_
# define DATABASE_HPP_

# include "IComponent.hpp"
# include <iostream>
# include <map>
# include <tuple>
# include <memory>

class Database
{
public:
	enum Type
	{
		INPUT,
		OUTPUT,
		UNDEFINED
	};
	static nts::IComponent	&addComponent(std::unique_ptr<nts::IComponent>, const std::string &, const std::string &);

	static std::map<std::unique_ptr<nts::IComponent>, std::tuple<Type, std::string, bool, bool>>	&getComponents();
	static nts::IComponent	&getComponentByName(const std::string &);
	static const std::string	&getNameByComponent(const nts::IComponent &);

	static void	isLinked(nts::IComponent &);
	static void	hasValue(nts::IComponent &);
private:
	static std::map<std::unique_ptr<nts::IComponent>, std::tuple<Type, std::string, bool, bool>>	_list;
};

#endif