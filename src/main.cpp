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
	std::unique_ptr<Parser>	parse;

	if (argc < 2)
		throw Exception("Too few arguments");
	parse = std::make_unique<Parser>(std::string(argv[1]));
	return (0);
}
