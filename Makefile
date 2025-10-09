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
FILES = ft_alltolower.c ft_base_point_c.c ft_count_out.c ft_printf.c ft_putstr_c.c ft_something_treat.c \
      ft_treat_char.c ft_treat_hex.c ft_treat_int.c ft_treat_point.c ft_treat_string.c ft_treat_uint.c
BONUS_FILES = ft_printf_bonus.c
INCS = .
NAME = libftprintf.a
SRCS = $(addprefix ./srcs/, $(FILES))
BONUS_SRCS = $(addprefix ./bonus/, $(BONUS_FILES))
OBJS = ${SRCS:.c=.o}
RM = rm -f
LIBC = ar rc
LIBR = ranlib
CFLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re bonus

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCS}

${NAME}: ${OBJS}
	${MAKE} -C ./libft
	cp libft/libft.a ${NAME}
	${LIBC} ${NAME} ${OBJS}
	${LIBR} ${NAME}

all: ${NAME}

bonus: ${OBJS} ${BONUS_SRCS:.c=.o}
	${MAKE} -C ./libft
	cp libft/libft.a ${NAME}
	${LIBC} ${NAME} ${OBJS} ${BONUS_SRCS:.c=.o}
	${LIBR} ${NAME}

clean:
	${MAKE} clean -C ./libft
	${RM} ${OBJS} ${BONUS_OBJS}
	${MAKE} -C ${LIBFT_DIR} clean

fclean: clean
	${RM} ${NAME}
	${MAKE} fclean -C ./libft

re: fclean all
