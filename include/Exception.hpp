//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// 
//

#pragma once

#include <exception>
#include <iostream>

class Exception : public std::exception
{
public:
	Exception(const std::string &);
};
