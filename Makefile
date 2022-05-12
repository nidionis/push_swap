# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: supersko <supersko@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/02 15:16:38 by supersko          #+#    #+#              #
#    Updated: 2022/05/12 13:41:28 by supersko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =  get_args.c lnk_fts.c pushing_fts.c print_lst.c pop_item.c

OBJS := ${SRCS:c=o}

NAME = push_swap
HEADERS = includes
LIBFT_DIR = libft/
LIBFTPRINTF_DIR = libftprintf/
LIBFT_AR = libft.a
LIBFTPRINTF_AR = libftprintf.a

INCLUDES = -I./$(HEADERS) $(LIBFTPRINTF_DIR)$(LIBFTPRINTF_AR) $(LIBFT_DIR)$(LIBFT_AR) -I./$(LIBFTPRINTF_DIR) -I./$(LIBFT_DIR)
CFLAGS = -Wall -Wextra -Werror

CC = gcc

all: ${NAME}

${NAME}: make_libftprintf make_libft
	$(CC) $(CFLAGS) $(INCLUDES) $(SRCS) -o $(NAME)
	
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

debug: ctags
	${CC} $(CFLAGS) $(INCLUDES) -g ${SRCS} -o $(NAME)
	lldb $(NAME)
	rm a.out

.PHONY: all clean fclean re
# If, for example, the file clean happened to be created running make clean would yield the confusing message:
# $ make clean
# make: `clean' is up to date.Makefile
