# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/13 15:10:10 by mkazuhik          #+#    #+#              #
#    Updated: 2025/10/19 03:04:29 by mkazuhik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
LIBFT = ./libft/libft.a
FILES = ft_alltolower.c ft_base_point_c.c ft_count_out.c ft_printf.c ft_putstr_c.c ft_something_treat.c \
      ft_treat_char.c ft_treat_hex.c ft_treat_int.c ft_treat_point.c ft_treat_string.c ft_treat_uint.c
BONUS_FILES = ft_printf_bonus.c ft_bonus_parse.c ft_bonus_format.c ft_bonus_utils.c \
			handlers/ft_bonus_handlers1a.c handlers/ft_bonus_handlers1b.c handlers/ft_bonus_handlers2a.c \
			handlers/ft_bonus_handlers2b.c handlers/ft_bonus_handlers2a_utils.c \
			numbers.c/ft_bonus_numbers_di.c numbers.c/ft_bonus_numbers_uxx.c numbers.c/ft_bonus_numbers_utils.c \
			numbers.c/ft_bonus_numbers_di_utils.c numbers.c/ft_bonus_numbers_uxx_utils.c \
			ft_bonus_parse_utils.c
INCS = -I. -I./bonus -I./srcs -I./libft
NAME = libftprintf.a
SRCS = $(addprefix ./srcs/, $(FILES))
BONUS_SRCS = $(addprefix ./bonus/, $(BONUS_FILES))
OBJS = ${SRCS:.c=.o}
BONUS_OBJS = ${BONUS_SRCS:.c=.o}
RM = rm -f
LIBC = ar rc
LIBR = ranlib
CFLAGS = -Wall -Wextra -Werror
BONUS_FLAG = .bonus_exists

.PHONY: all clean fclean re bonus

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I $@
${NAME}: ${OBJS}
	${MAKE} -C ./libft
	cp libft/libft.a ${NAME}
	${LIBC} ${NAME} ${OBJS}
	${LIBR} ${NAME}

all: ${NAME}

bonus: ${BONUS_FLAG}

${BONUS_FLAG}: ${OBJS} ${BONUS_OBJS}
	${MAKE} -C ./libft
	cp libft/libft.a ${NAME}
	${LIBC} ${NAME} ${BONUS_OBJS} ${OBJS}
	${LIBR} ${NAME}
	@touch ${BONUS_FLAG}

clean:
	${MAKE} clean -C ./libft
	${RM} ${OBJS} ${BONUS_OBJS}

fclean: clean
	${RM} ${NAME} ${BONUS_FLAG}
	${MAKE} fclean -C ./libft

re: fclean all
