# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/02 15:16:38 by supersko          #+#    #+#              #
#    Updated: 2025/02/01 05:34:16 by nidionis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =  get_args.c lnk_fts.c pushing_fts.c print_lst.c \
rotate.c verifications.c swap.c apply_instr.c get_next_line.c \
first_parsing.c algo.c reach.c small_lst.c b_dump.c data.c

OBJS := ${SRCS:c=o}

MAIN = main.c
BONUS_MAIN = checker.c

NAME = push_swap
DEBUG_NAME = a.out
BONUS_NAME = checker
HEADERS = includes
LIBFT_DIR = libft/
LIBFT_AR = libft.a
LIBS =  $(LIBFT_DIR)$(LIBFT_AR)

INCLUDES = -I./$(HEADERS) $(LIBS)  -I./$(LIBFT_DIR)include
CFLAGS = -Wall -Wextra -Werror -g3

CC = gcc

all: ${NAME}

${NAME}: make_libft
	$(CC) $(CFLAGS) $(SRCS) $(MAIN) $(INCLUDES) -o $(NAME)

bonus: make_libft
	$(CC) $(CFLAGS) $(INCLUDES) $(SRCS) $(BONUS_MAIN) -o $(BONUS_NAME)
	
%.o: %.c
	${CC} ${CFLAGS} $(INCLUDES) -c $<

make_libft:
	make -C libft

.PHONY: ctags
ctags:
	ctags *

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

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