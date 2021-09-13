SRCS	=	push_swap.c \
			chunksort.c \
			commands.c	\
			correctorder.c	\
			inputs.c	\
			joinparams.c	\
			manualcontrol.c	\
			printcolumns.c	\
			random_gen.c	\

OBJS = ${SRCS:.c=.o}
NAME = push_swap.a
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
	@${RM} ${OBJS}
fclean:		clean
	@${RM} ${NAME}
re:		fclean all