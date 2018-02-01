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
		)

SRC_HPP	=	$(addprefix include/,	\
		IComponent.hpp	\
		ManagerComponent.hpp	\
		Exception.hpp		\
		)

SRC	=	$(SRC_CPP)	\
		$(SRC_HPP)

OBJ	=	$(SRC:.cpp=.o)

CXXFLAGS	=	-W -Wall -Wextra -std=c++14

CXXFLAGS	+=	-Iinclude

RM	=	rm

CXX	=	g++

NAME	=	a.out

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CXX) $(OBJ) -o $(NAME) $(CXXFLAGS)

clean:
	$(RM) -f $(SRC_CPP:.cpp=.o)

fclean:	clean
	$(RM) -f $(NAME)

re:	fclean all
