//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// 
//

#include "Command.hpp"
#include "Exception.hpp"
#include "Database.hpp"
#include "component/Input.hpp"

Command::Command()
{
	std::string	line;
	std::string	command;
	std::string	value;
	std::size_t	pos;

	while (true){
		std::cout << "> ";
		if (!std::getline(std::cin, line))
			break;
		pos = line.find('=');
		if (pos == std::string::npos){
			command = line;
			parseCommand(command);
		}
		else{
			command = line.substr(0, pos);
			value = line.substr(pos + 1);
			input(command, value);
		}
	}
}

void	Command::parseCommand(const std::string &command)
{
	std::map<std::string, std::function<void ()>>	commands;

	commands["exit"] = std::bind(&Command::exit, this);
	commands["display"] = std::bind(&Command::display, this);
	commands["dump"] = std::bind(&Command::dump, this);
	commands["loop"] = std::bind(&Command::loop, this);
	commands["simulate"] = std::bind(&Command::simulation, this);
	if (commands.find(command) == commands.end())
		throw Exception("Command - " + command + ": not found");
	commands[command]();
}

void	Command::exit()
{
	std::exit(0);
}

void	Command::display()
{
	for (const auto &elem : Database::getComponents()){
		if (std::get<0>(elem.second) == Database::Type::OUTPUT){
			elem.first->dump();
		}
	}
}

void	Command::dump()
{
	for (const auto &elem : Database::getComponents()){
		elem.first->dump();
	}
}

void	Command::loop()
{
	for (const auto &elem : Database::getComponents()){
		if (std::get<0>(elem.second) == Database::Type::OUTPUT){
			elem.first->compute(1);
		}
	}
	loop();
}

void	Command::simulation()
{
	for (const auto &elem : Database::getComponents()){
		if (std::get<0>(elem.second) == Database::Type::OUTPUT){
			elem.first->compute(1);
			elem.first->dump();
		}
	}
}

void	Command::input(const std::string &input, const std::string &value)
{
	nts::Tristate	state = nts::Tristate::UNDEFINED;

	if (value == "1")
		state = nts::Tristate::TRUE;
	else if (value == "0")
		state = nts::Tristate::FALSE;
	for (const auto &elem : Database::getComponents()){
		if (std::get<1>(elem.second) != input)
			continue;
		if (std::get<0>(elem.second) <= Database::Type::CLOCK){
			(static_cast<nts::Input &>(*elem.first)).setValue(state);
			return;
		}
	}
	throw Exception("Command - " + input + ": input not found");
}
