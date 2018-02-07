//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// 
//

#include "Database.hpp"
#include "Exception.hpp"

std::map<std::unique_ptr<nts::IComponent>, std::tuple<Database::Type, std::string, bool, bool>>	Database::_list;

nts::IComponent	&Database::addComponent(std::unique_ptr<nts::IComponent> comp, const std::string &name, const std::string &type)
{
	Database::Type	kind = Database::Type::UNDEFINED;
	nts::IComponent	*pointer = comp.get();
	
	for (const auto &elem : _list){
		if (std::get<1>(elem.second) == name)
			throw Exception("Database - " + name + ": double usage of this name");
	}
	if (type == "output" || type == "input")
		kind = type == "output" ? Database::Type::OUTPUT : Database::Type::INPUT;
	_list[std::move(comp)] = std::make_tuple(kind, name, false, type != "input" ? true : false);
	return (*pointer);
}


std::map<std::unique_ptr<nts::IComponent>, std::tuple<Database::Type, std::string, bool, bool>>	&Database::getComponents()
{
	return (_list);
}

nts::IComponent	&Database::getComponentByName(const std::string &name)
{
	for (const auto &elem : _list){
		if (std::get<1>(elem.second) == name){
			return (*elem.first);
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

void    Database::isLinked(nts::IComponent &comp)
{
	for (auto &elem : _list){
		if (elem.first.get() == &comp){
			std::get<2>(elem.second) = true;
		}
	}
}

void    Database::hasValue(nts::IComponent &comp)
{
	for (auto &elem : _list){
		if (elem.first.get() == &comp){
			std::get<3>(elem.second) = true;
		}
	}
}