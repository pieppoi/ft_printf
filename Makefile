# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/13 15:10:10 by mkazuhik          #+#    #+#              #
#    Updated: 2025/10/09 20:47:25 by mkazuhik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft
FILES = ft_alltolower.c ft_base_point_c.c ft_count_out.c ft_printf.c ft_putstr_c.c ft_something_treat.c \
      ft_treat_char.c ft_treat_hex.c ft_treat_int.c ft_treat_point.c ft_treat_string.c ft_treat_uint.c
BONUS_FILES = ft_printf_bonus.c
INCS = .
BONUS_DIR = ./bonus
NAME = libftprintf.a
SRCS = $(addprefix ./srcs/, $(FILES))
BONUS_SRCS = $(addprefix ${BONUS_DIR}/, $(BONUS_FILES))
OBJS = ${SRCS:.c=.o}
BONUS_OBJS = ${BONUS_SRCS:.c=.o}
# Build set toggled by WITH_BONUS variable
SRCS_ALL = ${SRCS} $(if ${WITH_BONUS},${BONUS_SRCS})
OBJS_ALL = ${SRCS_ALL:.c=.o}
RM = rm -f
LIBC = ar rc
LIBR = ranlib
CFLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re bonus

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCS}

${NAME}: ${OBJS_ALL}
	${MAKE} -C ${LIBFT_DIR}
	cp ${LIBFT} ${NAME}
	${LIBC} ${NAME} ${OBJS_ALL}
	${LIBR} ${NAME}

all: ${NAME}

bonus:
	${MAKE} WITH_BONUS=1 all

clean:
	${MAKE} -C ${LIBFT_DIR} clean
	${RM} ${OBJS} ${BONUS_OBJS}

fclean: clean
	${RM} ${NAME}
	${MAKE} -C ${LIBFT_DIR} fclean

re: fclean all
