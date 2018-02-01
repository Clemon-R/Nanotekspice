//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// 
//

#include "Exception.hpp"
#include "ManagerComponent.hpp"

int	main(int argc, char **argv)
{
	if (argc < 2)
		throw Exception("Too few arguments");
	return (0);
}
