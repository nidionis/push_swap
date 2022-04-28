# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/02 15:16:38 by supersko          #+#    #+#              #
#    Updated: 2022/04/07 17:04:36 by supersko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR = ./src/
SRCS = *.c

OBJS = ${SRCS:.c=.o}

NAME = pushswap

HEADERS = push_swap.h libftprintf.h libft.h get_next_line.h
INC_DIR = ./include/
LIBFTPRINTF_DIR = ./ft_printf/
LIBFTPRINTF = libftprintf.a 
AR = ar rsu

CC = gcc
CFLAGS += -Wall -Werror -Wextra
CPPFLAGS += -I$(INC_DIR)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFTPRINTF)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LIBFTPRINTF) -o $(NAME)

$(LIBFTPRINTF): $(LIBFTPRINTF_DIR)$(LIBFTPRINTF)
	$(MAKE) -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)$(LIBFTPRINTF) .

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

test: $(NAME)
	./$(NAME)
	rm a.out

.PHONY: all clean fclean re
