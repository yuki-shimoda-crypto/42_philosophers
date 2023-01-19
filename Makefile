# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 16:37:16 by fedora            #+#    #+#              #
#    Updated: 2023/01/16 18:4 by yshimoda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	philo

SRCS			=	$(shell find src/ -name "*.c")

OBJS			=	$(SRCS:.c=.o)

INCLUDE			=	-I include

CC				=	cc

CFLAGS			=	-Wall -Wextra -Werror
DEBUG_FLAGS		=	-g -fsanitize=address -fsanitize=leak -fsanitize=undefined -pthread
GCC_FLAGS		=	
THREAD_FLAGS	=	-g -fsanitize=undefined -fsanitize=thread -pthread

.c.o:
				$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

PHONY			=	all
all:			$(NAME)

PHONY			+=	clean
clean:			
				$(RM) $(OBJS)

PHONY			+=	fclean
fclean:			clean
				$(RM) $(NAME)

PHONY			+=	re
re:				fclean all

PHONY			+=	debug
debug:			CFLAGS +=	$(DEBUG_FLAGS)
debug:			re

PHONY			+=	thread
thread:			CFLAGS +=	$(THREAD_FLAGS)
thread:			re

PHONY			+=	gcc
gcc:			CFLAGS =	$(GCC_FLAGS)
gcc:			re

PHONY			+=	valgrind
valgrind:		all
				valgrind --log-file=$(PWD)/log.txt --leak-check=full --tool=memcheck --leak-check=yes --show-reachable=yes --tool=helgrind ./$(NAME)

.PHONY:			$(PHONY)
