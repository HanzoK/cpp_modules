# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hanjkim <hanjkim@student.42vienna.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/06 16:27:15 by hanjkim           #+#    #+#              #
#    Updated: 2025/06/24 14:32:17 by hanjkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= phonebook

CXX			= c++

CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -MMD -MP

SRCS		= Contact.cpp \
			  PhoneBook.cpp \
			  main.cpp

OBJS		= ${SRCS:.cpp=.o}

DFILES	= ${SRCS:.cpp=.d}

RM			= rm -rf

all:	$(NAME)

$(NAME)	: $(OBJS)  
		$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

-include $(DFILES)
clean:
		$(RM) ${OBJS} ${DFILES}

fclean:	clean
		$(RM) $(NAME)

re: 	fclean all

.PHONY:	all clean fclean re
