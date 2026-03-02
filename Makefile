# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phwang <phwang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/25 23:59:26 by phwang            #+#    #+#              #
#    Updated: 2026/03/02 23:32:42 by phwang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test

CC = cc
INCLUDE = libasm/include
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDE)

LIBASM = libasm/libasm.a

# Source directories
SRC_DIR = tester/
OBJ_DIR = obj


TESTER_DIR = $(SRC_DIR)
TESTER_FILES = \
		ft_strcpy.c \
		ft_read.c \
		ft_write.c \
		ft_strcmp.c \
		ft_strlen.c \
		ft_strdup.c 
TESTER = $(addprefix $(TESTER_DIR), $(TESTER_FILES))

# Enlever .c pour créer les noms des exécutables
TARGETS = $(TESTER_FILES:.c=)

PMANDATORY =  $(addprefix , $(TESTER))
M_OBJS = $(PMANDATORY:$(SRC_DIR)%.c=$(OBJ_DIR)/%.o)

#COLOR SET
COLOR_RESET = \e[0m
COLOR_GREEN = \e[32m
COLOR_BLUE = \e[34m


all: $(TARGETS) $(M_OBJS)

$(OBJ_DIR)/%.o :  $(SRC_DIR)%.c 
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

%: $(OBJ_DIR)/%.o
	@make -s -C libasm
	@$(CC) $(CFLAGS) $< -o $@ $(LIBASM)

clean:
	@make -s -C libasm clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make -s -C libasm fclean
	@rm -f $(TARGETS)

re: fclean all

test: all
	@echo "Running all tests..."
	@for t in $(TARGETS); do \
		echo "$(COLOR_BLUE);=== Running $$t ===$(COLOR_RESET)"; \
		./$$t; \
		echo "$(COLOR_GREEN);=== End $$t ===$(COLOR_RESET)"; \
	done

.PHONY: all clean fclean re 