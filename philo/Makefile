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

SRCS			=	src/check.c				\
					src/create_threads.c	\
					src/eat_sleep_think.c	\
					src/init_arg.c			\
					src/libft.c				\
					src/main.c				\
					src/monitor.c			\
					src/utils.c				\
					src/utils_time.c

OBJ_DIR			=	obj
OBJS			=	$(SRCS:%.c=$(OBJ_DIR)/%.o)

INCLUDE			=	-I include

CC				=	cc

CFLAGS			=	-Wall -Wextra -Werror
DEBUG_FLAGS		=	-g -fsanitize=address  -fsanitize=undefined -pthread
THREAD_FLAGS	=	-g -fsanitize=thread -pthread

ifeq ($(shell uname -s), Linux)
DEBUG_FLAGS		+=	-fsanitize=leak
endif

$(OBJ_DIR)/%.o:%.c
				@mkdir -p $(@D)
				$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

PHONY			=	all
all:			$(NAME)

PHONY			+=	clean
clean:			
				$(RM) -r $(OBJ_DIR)

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

PHONY			+=	valgrind
valgrind:		all
				# valgrind --log-file=$(PWD)/log.txt --leak-check=full --tool=memcheck --leak-check=yes --show-reachable=yes --tool=helgrind ./$(NAME)
				valgrind --tool=helgrind ./philo 5 800 200 200 > ouput.txt

PHONY			+=	do
do:				all
				while [ 1 ]; do ./$(NAME) 200 1000 100 100 | tee -a output.txt && sleep 1;done

.PHONY:			$(PHONY)
