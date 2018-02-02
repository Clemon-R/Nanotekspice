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

int	main(int argc, char **argv)
{
	if (argc < 2)
		throw Exception("Too few arguments");
	Parser::parseFile(std::string(argv[1]));
	return (0);
}
