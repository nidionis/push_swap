# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: supersko <supersko@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/02 15:16:38 by supersko          #+#    #+#              #
#    Updated: 2024/11/26 15:00:21 by nidionis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_print_arg.c ft_print_chars.c ft_print_hexa.c ft_print_int.c ft_printf.c

OBJS = ${SRCS:.c=.o}

NAME = libftprintf.a

HEADER = libftprintf.h
LIBFT = libft.a
AR = ar rsu

LIBFT_DIR = ../libft/

CC = gcc
CFLAGS += -Wall -Werror -Wextra -I$(LIBFT_DIR)


all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_DIR)$(LIBFT)
	cp $(LIBFT_DIR)$(LIBFT) .
	$(AR) $(NAME) $(OBJS) $(LIBFT)

$(LIBFT_DIR)$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	rm -rf $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
