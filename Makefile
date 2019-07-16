##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## FTP
##

NAME	=	tilemap

MSRC	=	src/main.cpp
SRC		=	src/tilemap.cpp \
			src/tile.cpp \
			src/editor.cpp

MOBJ	=	$(MSRC:.cpp=.o)
OBJ		=	$(SRC:.cpp=.o)

CXX		=	g++
CXXFLAGS=	-Wall -Wextra -Werror -Iinclude
LDFLAGS	=	-lsfml-graphics -lsfml-system -lsfml-window

RM		=	rm -f

%.o:	%.cpp
	@$(CXX) -c -o $@ $< $(CXXFLAGS)
	@printf "\033[0;32m[compiled] % 59s\033[0m\n" $< | tr ' ' '.'

all:	$(NAME)

$(NAME):	$(MOBJ) $(OBJ)
	@$(CXX) -o $(NAME) $(MOBJ) $(OBJ) $(LDFLAGS)
	@printf "\033[0;36m[built] % 62s\033[0m\n" $(NAME) | tr ' ' '.'

clean:
	@$(RM) $(OBJ)
	@printf "\033[0;31m[deleted] % 60s\033[0m\n" $(OBJ) | tr ' ' '.'
	@$(RM) $(MOBJ)
	@printf "\033[0;31m[deleted] % 60s\033[0m\n" $(MOBJ) | tr ' ' '.'

fclean:		clean
	@$(RM) $(NAME)
	@printf "\033[0;31m[deleted] % 60s\033[0m\n" $(NAME) | tr ' ' '.'

re:		fclean all

debug: CFLAGS += -g
debug: re

.PHONY:	all clean fclean re debug
.SILENT:clean fclean
