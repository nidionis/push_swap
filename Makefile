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

SRCS = *.c

OBJS = ${SRCS:.c=.o}

NAME = push_swap

CFLAGS = -Wall -Werror -Wextra

HEADER = push_swap.h

CC = gcc

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -c $(SRCS) $(HEADER)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

test:
	$(CC) $(SRCS) $(SRCS_BONUS) $(HEADER)
	./a.out

debug:
	$(CC) -g $(SRCS) $(SRCS_BONUS) $(HEADER)
	lldb a.out
	rm a.out

.PHONY: all clean fclean re
