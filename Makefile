# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: supersko <supersko@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/02 15:16:38 by supersko          #+#    #+#              #
#    Updated: 2022/05/16 19:08:28 by supersko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =  init_next_prev.c  get_args.c lnk_fts.c pushing_fts.c print_lst.c rotate.c verifications.c swap.c apply_instr.c get_next_line.c my_algo.c bubble_sort.c # algo_tree.c

OBJS := ${SRCS:c=o}

MAIN = main.c
BONUS_MAIN = checker.c

NAME = push_swap
DEBUG_NAME = a.out
BONUS_NAME = checker
HEADERS = includes
LIBFT_DIR = libft/
#LINKED_LST_DIR = linked_lst/
LIBFTPRINTF_DIR = libftprintf/
LIBFT_AR = libft.a
LIBFTPRINTF_AR = libftprintf.a
#LINKED_LST_AR = linked_lst.a
LIBS = $(LIBFTPRINTF_DIR)$(LIBFTPRINTF_AR) $(LIBFT_DIR)$(LIBFT_AR) # $(LINKED_LST_DIR)$(LINKED_LST_AR)

INCLUDES = -I./$(HEADERS) $(LIBS) -I./$(LIBFTPRINTF_DIR) -I./$(LIBFT_DIR)
CFLAGS = -Wall -Wextra -Werror

CC = gcc

all: ${NAME}

${NAME}: make_libftprintf make_libft
	$(CC) $(CFLAGS) $(INCLUDES) $(SRCS) $(MAIN) -o $(NAME)

bonus:
	$(CC) $(CFLAGS) $(INCLUDES) $(SRCS) $(BONUS_MAIN) -o $(BONUS_NAME)
	
%.o: %.c
	${CC} ${CFLAGS} $(INCLUDES) -c $<

make_libft:
	make -C libft

make_libftprintf:
	make -C libftprintf

.PHONY: ctags
ctags:
	ctags *

clean:
	rm -rf ${OBJS}
	rm -rf ${DEBUG_NAME}
	make clean -C libft
	make clean -C libftprintf

fclean: clean
	rm -rf ${NAME}
	make fclean -C libft
	make fclean -C libftprintf

re: fclean all

test: ctags
	${CC} $(CFLAGS) $(INCLUDES) ${SRCS} -o $(NAME)
	./$(NAME)
	rm a.out

debugfile: ctags
	$(CC) $(CFLAGS) -g $(INCLUDES) $(SRCS) $(MAIN) -o $(DEBUG_NAME)

debug: debugfile
	lldb $(DEBUG_NAME)
	rm $(DEBUG_NAME)

valgrind_: ctags
	${CC} $(CFLAGS) $(INCLUDES) -g ${SRCS} -o $(DEBUG_NAME)

.PHONY: all clean fclean re
# If, for example, the file clean happened to be created running make clean would yield the confusing message:
# $ make clean
# make: `clean' is up to date.Makefile
