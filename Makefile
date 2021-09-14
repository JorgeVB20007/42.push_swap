# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvacaris <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/14 23:35:02 by jvacaris          #+#    #+#              #
#    Updated: 2021/09/14 23:35:05 by jvacaris         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	push_swap.c \
			chunksort.c \
			commands.c	\
			correctorder.c	\
			fewnums.c	\
			inputs.c	\
			joinparams.c	\
			logmanagement.c	\

OBJS = ${SRCS:.c=.o}
NAME = push_swap
LIBFT = libft.a
CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra

all:		${NAME}
${NAME}:	${OBJS} ${LIBFT}
			ar rc ${NAME} ${OBJS}
${LIBFT}:	
			make -C ./libft/ libft.a
clean:
	@${RM} ${OBJS} libft/*.o
fclean:		clean
	@${RM} ${NAME} libft/${LIBFT} libft/*.o
re:		fclean all
