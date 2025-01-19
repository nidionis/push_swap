# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/02 15:16:38 by supersko          #+#    #+#              #
#    Updated: 2025/01/19 03:32:11 by nidionis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = *.c

OBJS := ${SRCS:c=o}

#MAIN = main.c
BONUS_MAIN = checker.c

NAME = push_swap
DEBUG_NAME = a.out
BONUS_NAME = checker
HEADERS = -I./include -I./libft/include
LIBFT_DIR = libft/
LIBFT_AR = libft.a
LIBS = $(LIBFT_DIR)$(LIBFT_AR)

INCLUDES = $(HEADERS) -L./$(LIBFT_DIR) -L include $(LIBS) -I./$(LIBFT_DIR)
CFLAGS = -Wall -Wextra -Werror

CC = gcc

all: ${NAME}

${NAME}:  make_libft
	$(CC) $(CFLAGS) $(SRCS) $(MAIN) $(INCLUDES) -o $(NAME)

bonus:  make_libft
	$(CC) $(CFLAGS) $(INCLUDES) $(SRCS) $(BONUS_MAIN) -o $(BONUS_NAME)
	
%.o: %.c
	${CC} ${CFLAGS} $(INCLUDES) -c $<

make_libft:
	make -C libft

ctags:
	ctags *

clean:
	rm -f $(OBJS)
	rm -f $(DEBUG_NAME)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)
	make fclean -C libft

re: fclean all

test: ctags
	${CC} $(CFLAGS) $(INCLUDES) ${SRCS} -o $(NAME)
	./$(NAME)
	rm a.out

debugfile: ctags
	$(CC) $(CFLAGS) -g $(SRCS) $(MAIN) $(INCLUDES) -o $(DEBUG_NAME)

bonusdebugfile: ctags
	$(CC) $(CFLAGS) -g $(SRCS) $(BONUS_MAIN) $(INCLUDES) -o $(BONUS_NAME) -fsanitize=address

debug: debugfile
	lldb $(DEBUG_NAME)
	rm $(DEBUG_NAME)

.PHONY: all clean fclean re
