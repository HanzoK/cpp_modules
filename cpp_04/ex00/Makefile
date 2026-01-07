# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hanjkim <hanjkim@student.42vienna.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/06 16:27:15 by hanjkim           #+#    #+#              #
#    Updated: 2025/08/05 14:38:20 by hanjkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= polymorphism

CXX			= c++

CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

SRCS		= main.cpp \
			  Animal.cpp \
			  Cat.cpp \
			  Dog.cpp \
			  WrongAnimal.cpp \
			  WrongCat.cpp \

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
