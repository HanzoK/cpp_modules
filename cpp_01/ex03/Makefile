# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hanjkim <hanjkim@student.42vienna.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/06 16:27:15 by hanjkim           #+#    #+#              #
#    Updated: 2025/06/20 18:48:35 by hanjkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= unnecessaryViolence

CXX			= c++

CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -ftrapv

SRCS		= main.cpp \
			  HumanA.cpp \
			  HumanB.cpp \
			  Weapon.cpp \

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
