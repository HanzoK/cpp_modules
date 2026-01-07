# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hanjkim <hanjkim@student.42vienna.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/06 16:27:15 by hanjkim           #+#    #+#              #
#    Updated: 2025/11/27 15:48:45 by hanjkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= MutatedAbomination

CXX			= c++

CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -MMD -MP

SRCS		= main.cpp \

OBJS		= ${SRCS:.cpp=.o}

DEPS		= ${SRCS:.cpp=.d}

RM			= rm -rf

-include ${DEPS}

all:	$(NAME)

$(NAME)	: $(OBJS)
		$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
		$(RM) ${OBJS} ${DEPS}

fclean:	clean
		$(RM) $(NAME)

re: 	fclean all

.PHONY:	all clean fclean re
