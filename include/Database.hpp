//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// 
//

#ifndef DATABASE_HPP_
# define DATABASE_HPP_

# include "Component.hpp"
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
		CLOCK,
		UNDEFINED,
		OUTPUT
	};
	static nts::IComponent	&addComponent(std::unique_ptr<nts::IComponent>,
					      const std::string &,
					      const std::string &);
	static std::map<std::unique_ptr<nts::IComponent>, std::tuple<Type, std::string, bool, bool>>	&getComponents();
	static nts::Component	*getComponentByName(const std::string &);
	static void	isLinked(nts::IComponent &);
	static void	hasValue(nts::IComponent &);
	static Database::Type	getState(const nts::IComponent &);
private:
	static Database::Type	getType(const std::string &);
	static std::map<std::unique_ptr<nts::IComponent>, std::tuple<Type, std::string, bool, bool>>	_list;
};

#endif
