# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hanjkim <hanjkim@student.42vienna.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/06 16:27:15 by hanjkim           #+#    #+#              #
#    Updated: 2025/11/17 17:12:39 by oohnivch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= bureaucrat

CXX			= c++

CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

SRCS		= main.cpp \
			  Bureaucrat.cpp \
			  AForm.cpp \
			  PresidentialPardonForm.cpp \
			  RobotomyRequestForm.cpp \
			  ShrubberyCreationForm.cpp \
			  Intern.cpp \

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
