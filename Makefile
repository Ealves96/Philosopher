# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jralph <jralph@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/15 17:13:14 by ealves            #+#    #+#              #
#    Updated: 2023/10/04 17:43:22 by jralph           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	philo

SRCS			= algo.c check_arg.c check_philo.c eat.c init.c main.c utils.c

OBJS			=	${SRCS:.c=.o}

HEAD			=	-I includes

CFLAGS			=	-Wall -Werror -Wextra -g

all				:	${NAME}

.c.o	:
		@cc ${CFLAGS} -c $< -o ${<:.c=.o} -I includes/

$(NAME) : $(OBJS)
	cc $(OBJS) -o $(NAME)

clean			:
					rm -rf ${OBJS}

fclean			:	clean
					rm -rf ${NAME}

re				:	fclean all

.PHONY			:	all clean fclean re
