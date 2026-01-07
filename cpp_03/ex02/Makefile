# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hanjkim <hanjkim@student.42vienna.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/06 16:27:15 by hanjkim           #+#    #+#              #
#    Updated: 2025/07/23 22:39:21 by hanjkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= FragTrap

CXX			= c++

CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

SRCS		= main.cpp \
			  ClapTrap.cpp \
			  ScavTrap.cpp \
			  FragTrap.cpp	\

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
