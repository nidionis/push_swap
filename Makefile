# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/02 15:16:38 by supersko          #+#    #+#              #
#    Updated: 2025/01/20 00:35:07 by nidionis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and Flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror
HEADERS = -I./include -I./libft/include
LIBFT_DIR = -Llibft
LIBFT_AR = -lft
LIBS = $(LIBFT_DIR) $(LIBFT_AR)

# Folders and Files
SRC_DIR = src
OBJ_DIR = obj
SRCS = $(filter-out $(SRC_DIR)/main.c, $(wildcard $(SRC_DIR)/*.c))
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
MAIN = main.c
NAME = push_swap

# Rules
.PHONY: all clean fclean re make_libft

all: $(NAME)

# Create executable
$(NAME): make_libft $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(HEADERS) $(OBJS) $(MAIN) -o $(NAME) $(LIBS)

# Create obj directory and compile source files into obj directory
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

# Ensure obj directory exists
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Build libft
make_libft:
	$(MAKE) -C libft

# Clean object files
clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) clean -C libft

# Full clean (including binary)
fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C libft

# Rebuild everything
re: fclean all
