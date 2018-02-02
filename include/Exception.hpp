//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// 
//

#ifndef EXCEPTION_HPP_
# define EXCEPTION_HPP_

# include <exception>
# include <iostream>

class Exception : public std::exception
{
public:
	Exception(const std::string &);
};
#endif
