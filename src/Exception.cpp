//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// 
//

#include "Exception.hpp"

Exception::Exception(const std::string &text)
{
	std::cerr << text << std::endl;
}
