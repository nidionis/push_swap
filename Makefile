LIBS_DIR = my_libs
OBJ_DIR = obj
SRCS = get_args.c main.c
OBJS = $(SRCS:.c=.o)
LIBS = $(LIBS_DIR)/libft.a $(LIBS_DIR)/libftprintf.a $(LIBS_DIR)/linked_lst.a

NAME = push_swap

#CFLAGS += -Wall -Werror -Wextra  -I./includes -I./$(LIBS_DIR) -I./$(LIBS_DIR)/includes
CFLAGS += -I./includes -I./$(LIBS_DIR) -I./$(LIBS_DIR)/includes

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(LIBS) $(OBJS) -o $(NAME)

#
#$(LIBFTPRINTF): $(LIBFTPRINTF_DIR)
#	$(MAKE) -C $(LIBFTPRINTF_DIR)
#	cp $(LIBFTPRINTF_DIR)$(LIBFTPRINTF) .
#
clean:
	rm $(OBJS)
	$(MAKE) clean -C $(LIBS_DIR)/libft
	$(MAKE) clean -C $(LIBS_DIR)/libftprintf
	$(MAKE) clean -C $(LIBS_DIR)/linked_lst

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(LIBFTPRINTF_DIR) fclean
	rm -rf $(NAME)

#re: fclean all
#
#test: $(NAME)
#	./$(NAME)
#	rm a.out
#
#.PHONY: all clean fclean re
