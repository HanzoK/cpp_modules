# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hanjkim <hanjkim@student.42vienna.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/06 16:27:15 by hanjkim           #+#    #+#              #
#    Updated: 2025/11/30 18:15:52 by hanjkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= RPN

CXX			= c++

CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -MMD -MP

SRCS		= main.cpp \
			  RPN.cpp \

DEPS		= ${SRCS:.cpp=.d}

OBJS		= ${SRCS:.cpp=.o}

RM			= rm -rf

all:	$(NAME)

-include $(DEPS)

$(NAME)	: $(OBJS)
		$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
		$(RM) ${OBJS} ${DEPS}

fclean:	clean
		$(RM) $(NAME)

re: 	fclean all

.PHONY:	all clean fclean re
