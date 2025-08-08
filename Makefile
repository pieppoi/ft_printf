# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/13 15:10:10 by mkazuhik          #+#    #+#              #
#    Updated: 2024/07/30 17:29:43 by mkazuhik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
LIBFT = ./libft/libft.a
SRCS = ft_alltolower.c ft_base_point_c.c ft_count_out.c ft_printf.c ft_putstr_c.c ft_something_treat.c\
		ft_treat_char.c ft_treat_hex.c ft_treat_int.c ft_treat_point.c ft_treat_string.c ft_treat_uint.c
INCS = includes
NAME = libftprintf.a
OBJS = ${SRCS:.c=.o}
RM = rm -f
LIBC = ar rc
LIBR = ranlib
CFLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCS}

${NAME}: ${OBJS}
	${MAKE} -C ./libft
	cp libft/libft.a ${NAME}
	${LIBC} ${NAME} ${OBJS}
	${LIBR} ${NAME}

all: ${NAME}

clean:
	$(MAKE) clean -C ./libft
	${RM} ${OBJS}

fclean: clean
	$(MAKE) fclean -C ./libft
	${RM} ${NAME}

re: fclean all