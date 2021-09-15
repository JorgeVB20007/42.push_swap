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
			chunksort_returntoa.c	\
			commands.c	\
			commands_slide.c	\
			correctorder.c	\
			fewnums.c	\
			inputs.c	\
			joinparams.c	\
			logmanagement.c	\

OBJS = ${SRCS:.c=.o}
NAME = push_swap
LIBFT = libft.a
LIBFT_PATH = ./libft/
CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra

all:		${NAME}
${NAME}:	${OBJS} ${LIBFT}
			${CC} ${CFLAGS} ${LIBFT_PATH}${LIBFT} ${OBJS} -o ${NAME} 
${LIBFT}:	
			make -C ${LIBFT_PATH}
clean:
	@${RM} ${OBJS}
	@make clean -C ${LIBFT_PATH}
	@echo ".o's are no more!"
fclean:		clean
	@${RM} ${NAME} libft/${LIBFT}
	@echo "(including .a's)"
re:		fclean all
.PHONY: all clean fclean re