##
## EPITECH PROJECT, 2018
## nanotekspice
## File description:
## 
##

SRC_CPP	=	$(addprefix src/,	\
		Exception.cpp	\
		main.cpp	\
		)

SRC_CPP	+=	$(addprefix src/component/,	\
		ManagerComponent.cpp	\
		Input.cpp	\
		Output.cpp	\
		4001.cpp	\
		)

SRC_CPP	+=	$(addprefix src/parser/,	\
		Parser.cpp	\
		)

SRC_HPP	=	$(addprefix include/,	\
		IComponent.hpp	\
		ManagerComponent.hpp	\
		Exception.hpp		\
		Parser.hpp		\
		component/Input.hpp	\
		component/Output.hpp	\
		component/4001.hpp	\
		)

SRC	=	$(SRC_CPP)	\
		$(SRC_HPP)

OBJ	=	$(SRC:.cpp=.o)

CXXFLAGS	=	-W -Wall -Wextra -std=c++14 -g3

CXXFLAGS	+=	-Iinclude

RM	=	rm

CXX	=	g++

NAME	=	a.out

all:	$(NAME)

$(NAME):	$(OBJ)
	@$(CXX) $(OBJ) -o $(NAME) $(CXXFLAGS)

clean:
	$(RM) -f $(SRC_CPP:.cpp=.o)

fclean:	clean
	$(RM) -f $(NAME)

re:	fclean all
