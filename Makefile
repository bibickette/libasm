# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phwang <phwang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/25 23:59:26 by phwang            #+#    #+#              #
#    Updated: 2026/03/02 16:50:57 by phwang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test

CC = cc
INCLUDE = libasm/include
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDE) -std=c99

LIBASM = libasm/libasm.a

# Source directories
SRC_DIR = tester/
OBJ_DIR = obj


TESTER_DIR = $(SRC_DIR)
TESTER_FILES = \
		ft_strcpy.c \
		ft_write.c \
		ft_strcmp.c \
		ft_strlen.c
TESTER = $(addprefix $(TESTER_DIR), $(TESTER_FILES))

# Enlever .c pour créer les noms des exécutables
TARGETS = $(TESTER_FILES:.c=)

PMANDATORY =  $(addprefix , $(TESTER))
M_OBJS = $(PMANDATORY:$(SRC_DIR)%.c=$(OBJ_DIR)/%.o)


all: $(TARGETS) $(M_OBJS)

$(OBJ_DIR)/%.o :  $(SRC_DIR)%.c 
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

%: $(OBJ_DIR)/%.o
	@make -s -C libasm
	$(CC) $(CFLAGS) $< -o $@ $(LIBASM)

clean:
	@make -s -C libasm clean
	rm -rf $(OBJ_DIR)

fclean: clean
	@make -s -C libasm fclean
	rm -f $(TARGETS)

re: fclean all

.PHONY: all clean fclean re 