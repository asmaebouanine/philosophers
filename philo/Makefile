# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/03 11:17:53 by asbouani          #+#    #+#              #
#    Updated: 2025/07/20 16:11:17 by asbouani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc

CFLAGS = -Wall -Wextra -Werror

HEADER = philo.h

SRCS = philo.c utils.c init.c routine.c check_sumilation.c start_sumilation.c

OBJS = ${SRCS:.c=.o}

all: ${NAME}

%.o: %.c ${HEADER}
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS} ${HEADER}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}
	
re: fclean all

.PHONY: clean