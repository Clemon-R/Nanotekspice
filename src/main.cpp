//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// 
//

#include <memory>
#include "Exception.hpp"
#include "ManagerComponent.hpp"
#include "Parser.hpp"
#include "Database.hpp"
#include "Parameter.hpp"
#include "Command.hpp"

int	main(int argc, char **argv)
{
	if (argc < 2)
		throw Exception("Too few arguments");
	Parser::parseFile(std::string(argv[1]));
	Parameter::parseParams(2, argc, argv);
	Parser::checkSettings();
	for (const auto &elem : Database::getComponents()){
		if (std::get<0>(elem.second) == Database::Type::OUTPUT){
			elem.first->compute(1);
			elem.first->dump();
		}
	}
	std::make_unique<Command>();
	return (0);
}
