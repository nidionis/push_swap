# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile.test                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/02 15:16:38 by supersko          #+#    #+#              #
#    Updated: 2025/03/07 21:22:35 by nidionis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBRARIES = ft
LIB_NAMES = $(addprefix lib, $(LIBRARIES))
LIB_DIR = ./lib

INCLUDE_DIRS = ./include
INCLUDE_DIRS += $(addsuffix /include,$(addprefix $(LIB_DIR)/,$(LIB_NAMES)))

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

LDFLAGS = $(addprefix -L$(LIB_DIR)/,$(LIB_NAMES))
LDLIBS = $(addprefix -l,$(LIBRARIES))
LIBS = $(addprefix $(LIB_DIR)/,$(LIB_NAMES))

SRC_DIR = ./src
SRCS = $(shell find $(SRC_DIR) -type f -name "*.c")
MAIN = main.c

OBJ_DIR = ./obj
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS)) $(OBJ_DIR)/main.o

INCLUDES = $(addprefix -I,$(INCLUDE_DIRS))

all: make_libs $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(LDFLAGS) $(OBJS) -o $@ $(LDLIBS)

make_libs:
	@for lib in $(LIB_NAMES); do \
		$(MAKE) -C $(LIB_DIR)/$$lib $(MAKECMDGOALS); \
	done

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/main.o: $(MAIN) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)
	@for lib in $(LIB_NAMES); do \
		$(MAKE) -C $(LIB_DIR)/$$lib clean; \
	done

fclean: clean
	rm -f $(NAME)
	@for lib in $(LIB_NAMES); do \
		$(MAKE) -C $(LIB_DIR)/$$lib fclean; \
	done

re: fclean all

.PHONY: all clean fclean re make_libs
