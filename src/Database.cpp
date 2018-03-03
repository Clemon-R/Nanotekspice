//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// 
//

#include "Database.hpp"
#include "Component.hpp"
#include "Exception.hpp"

std::map<std::unique_ptr<nts::IComponent>,
	 std::tuple<Database::Type, std::string, bool, bool>>	Database::_list;

nts::IComponent	&Database::addComponent(std::unique_ptr<nts::IComponent> comp,
const std::string &name, const std::string &type)
{
	nts::IComponent	*pointer = comp.get();
	
	for (const auto &elem : _list){
		if (std::get<1>(elem.second) == name)
			throw Exception("Database - " + name +
					": double usage of this name");
	}
	(static_cast<nts::Component *>(pointer))->setName(name);
	_list[std::move(comp)] = std::make_tuple(getType(type), name, false,
						 type != "input" ? true : false);
	return (*pointer);
}

Database::Type	Database::getType(const std::string &type)
{
	if (type == "input" || type == "clock")
		return (type == "input" ? Database::Type::INPUT :
			Database::Type::CLOCK);
	else if (type == "output")
		return (Database::Type::OUTPUT);
	return (Database::Type::UNDEFINED);
}


std::map<std::unique_ptr<nts::IComponent>,
	 std::tuple<Database::Type,
		    std::string, bool, bool>>	&Database::getComponents()
{
	return (_list);
}

nts::Component	*Database::getComponentByName(const std::string &name)
{
	for (const auto &elem : _list){
		if (std::get<1>(elem.second) == name){
			return (static_cast<nts::Component *>(elem.first.get()));
		}
	}
	throw Exception("Database - " + name + ": component not found");
}

const std::string       &Database::getNameByComponent(const nts::IComponent &comp)
{
	for (const auto &elem : _list){
		if (elem.first.get() == &comp)
			return (std::get<1>(elem.second));
	}
	throw Exception("Database: impossible to find name of one component");
}

void	Database::isLinked(nts::IComponent &comp)
{
	for (auto &elem : _list){
		if (elem.first.get() == &comp){
			std::get<2>(elem.second) = true;
		}
	}
}

void	Database::hasValue(nts::IComponent &comp)
{
	for (auto &elem : _list){
		if (elem.first.get() == &comp){
			std::get<3>(elem.second) = true;
		}
	}
}

Database::Type	Database::getState(const nts::IComponent &comp)
{
	for (const auto &elem : _list){
		if (elem.first.get() == &comp){
			return (std::get<0>(elem.second));
		}
	}
	throw Exception("Database: component not found");
}
