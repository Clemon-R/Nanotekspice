//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// 
//

#ifndef COMMAND_HPP_
# define COMMAND_HPP_

# include <iostream>
# include <map>
# include <functional>

class Command
{
public:
	Command();
	~Command() = default;

private:
	void	parseCommand(const std::string &);

	void	exit();
	void	display();
	void	dump();
	void	loop();
	void	simulation();
	void	input(const std::string &, const std::string &);
};

#endif
