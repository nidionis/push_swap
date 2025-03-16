# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/02 15:16:38 by supersko          #+#    #+#              #
#    Updated: 2025/03/07 22:44:20 by nidionis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CHECKER = checker

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
SRCS = $(shell find $(SRC_DIR) -type f -name "*.c" -not -path "*/checker/*")
MAIN = main.c
CHECKER_SRC = $(SRC_DIR)/checker/checker.c

OBJ_DIR = ./obj
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS)) $(OBJ_DIR)/main.o
CHECKER_OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(CHECKER_SRC))

INCLUDES = $(addprefix -I,$(INCLUDE_DIRS))

all: make_libs $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(LDFLAGS) $(OBJS) -o $@ $(LDLIBS)

make_libs:
	@for lib in $(LIB_NAMES); do \
		if [ "$(MAKECMDGOALS)" != "checker" ]; then \
			$(MAKE) -C $(LIB_DIR)/$$lib $(MAKECMDGOALS); \
		else \
			$(MAKE) -C $(LIB_DIR)/$$lib; \
		fi \
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
	rm -f $(NAME) $(CHECKER)
	@for lib in $(LIB_NAMES); do \
		$(MAKE) -C $(LIB_DIR)/$$lib fclean; \
	done

re: fclean all

checker: make_libs $(OBJS) $(CHECKER_OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) $(LDFLAGS) $(filter-out $(OBJ_DIR)/main.o, $(OBJS)) $(CHECKER_OBJ) -o $(CHECKER) $(LDLIBS)

visual: $(NAME)
	cd push_swap_visualizer/build && ./bin/visualizer

.PHONY: all clean fclean re make_libs checker
