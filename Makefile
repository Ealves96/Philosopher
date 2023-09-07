# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ealves <ealves@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/15 17:13:14 by ealves            #+#    #+#              #
#    Updated: 2023/09/07 12:14:24 by ealves           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	philo

SRCS			=	main.c utils.c init.c\
					algo.c

OBJS			=	${SRCS:.c=.o}

# HEAD			=	-Iincludes

CFLAGS			=	-Wall -Werror -Wextra -D BENCH=0 -g

all				:	${NAME}

.c.o	:
		@cc  ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME) : $(OBJS)
	cc $(OBJS) -o $(NAME)

clean			:
					rm -rf ${OBJS}

fclean			:	clean
					rm -rf ${NAME}

re				:	fclean all

.PHONY			:	all clean fclean re
