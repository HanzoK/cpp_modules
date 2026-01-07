# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hanjkim <hanjkim@student.42vienna.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/06 16:27:15 by hanjkim           #+#    #+#              #
#    Updated: 2025/08/16 20:49:35 by hanjkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= interface

CXX			= c++

CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -g -pedantic

SRCS		= main.cpp \
			  Character.cpp \
			  Cure.cpp \
			  Ice.cpp \
			  MateriaSource.cpp \
			  AMateria.cpp \
			  IMateriaSource.cpp \

OBJS		= ${SRCS:.cpp=.o}

RM			= rm -rf

all:	$(NAME)

$(NAME)	: $(OBJS)
		$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
		$(RM) ${OBJS}

fclean:	clean
		$(RM) $(NAME)

re: 	fclean all

.PHONY:	all clean fclean re
