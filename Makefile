##
## EPITECH PROJECT, 2018
## nanotekspice
## File description:
## 
##

SRC_CPP	=	$(addprefix src/,	\
		Exception.cpp	\
		Database.cpp	\
		Command.cpp	\
		LogicBinary.cpp	\
		main.cpp	\
		)

SRC_CPP	+=	$(addprefix src/component/,	\
		ManagerComponent.cpp	\
		fourGate.cpp	\
		Input.cpp	\
		True.cpp	\
		False.cpp	\
		Clock.cpp	\
		Output.cpp	\
		4001.cpp	\
		4008.cpp	\
		4011.cpp	\
		4030.cpp	\
		4071.cpp	\
		)

SRC_CPP	+=	$(addprefix src/parser/,	\
		Parser.cpp	\
		Parameter.cpp	\
		)

SRC_HPP	=	$(addprefix include/,	\
		IComponent.hpp	\
		ManagerComponent.hpp	\
		Exception.hpp		\
		Database.hpp		\
		Parser.hpp		\
		Parameter.hpp		\
		Command.hpp		\
		LogicBinary.hpp	\
		component/Input.hpp	\
		component/fourGate.hpp	\
		component/True.hpp	\
		component/False.hpp	\
		component/Clock.hpp	\
		component/Output.hpp	\
		component/4001.hpp	\
		component/4008.hpp	\
		component/4011.hpp	\
		component/4030.hpp	\
		component/4071.hpp	\
		)

SRC	=	$(SRC_CPP)	\
		$(SRC_HPP)

OBJ	=	$(SRC:.cpp=.o)

CXXFLAGS	=	-W -Wall -Wextra -std=c++14 -g3

CXXFLAGS	+=	-Iinclude

RM	=	rm

CXX	=	g++

NAME	=	nanotekspice

all:	$(NAME)

$(NAME):	$(OBJ)
	@$(CXX) $(OBJ) -o $(NAME) $(CXXFLAGS)

clean:
	$(RM) -f $(SRC_CPP:.cpp=.o)

fclean:	clean
	$(RM) -f $(NAME)

re:	fclean all
