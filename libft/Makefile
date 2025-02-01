CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude

SRC_DIR = src
OBJ_DIR = obj
INCLUDE_DIR = include

FILES = ft_atoi.c ft_errmsg.c ft_isascii.c ft_itoa.c \
		ft_lstclear.c ft_lstlast.c ft_lstsize.c ft_memcpy.c \
		ft_putendl_fd.c ft_split.c ft_striteri.c \
		ft_strlcpy.c ft_strncmp.c ft_strtrim.c ft_toupper.c \
		ft_bzero.c ft_isalnum.c ft_isdigit.c ft_lstadd_back.c \
		ft_lstdelone.c ft_lstmap.c ft_memchr.c ft_memmove.c \
		ft_putnbr_fd.c ft_strchr.c ft_strjoin.c \
		ft_strlen.c ft_strnstr.c ft_substr.c ft_calloc.c ft_isalpha.c \
		ft_isprint.c ft_lstadd_front.c ft_lstiter.c ft_lstnew.c \
		ft_memcmp.c ft_memset.c ft_putchar_fd.c ft_putstr_fd.c \
		ft_strdup.c  ft_strlcat.c   ft_strmapi.c  ft_strrchr.c  ft_tolower.c \
		ft_atoi_err.c ft_wd_count.c ft_get_next_wd.c

SRCS = $(addprefix $(SRC_DIR)/, $(FILES))

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

NAME = libft.a

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJS)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I./include -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re