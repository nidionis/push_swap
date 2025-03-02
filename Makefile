# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/02 15:16:38 by supersko          #+#    #+#              #
#    Updated: 2025/03/02 16:40:32 by nidionis         ###   ########.fr        #
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

$(OBJ_DIR)/main.o: main.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	@for lib in $(LIB_NAMES); do \
		$(MAKE) -C $(LIB_DIR)/$$lib clean; \
	done
	rm -rf $(OBJ_DIR)

fclean: clean
	@for lib in $(LIB_NAMES); do \
		$(MAKE) -C $(LIB_DIR)/$$lib fclean; \
	done
	rm -f $(NAME)

re: fclean all

install_visualizer:
	git clone https://github.com/o-reo/push_swap_visualizer.git
	cd push_swap_visualizer
	mkdir build
	cd build
	cmake ..
	make

visual:
	make
	cd push_swap_visualizer/build && ./bin/visualizer && cd -
	cd -

.PHONY: all clean fclean re make_libs
