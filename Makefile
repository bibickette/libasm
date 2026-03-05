# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phwang <phwang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/25 23:59:26 by phwang            #+#    #+#              #
#    Updated: 2026/03/06 00:07:37 by phwang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = all_tests

CC = cc
INCLUDE = libasm/include
TESTER_INCLUDE = tester/include
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDE) -I$(TESTER_INCLUDE)

LIBASM = libasm/libasm.a

# Source directories
SRC_DIR = tester/
OBJ_DIR = obj


TESTER_DIR = $(SRC_DIR)src
TESTER_FILES = \
		ft_strlen.c \
		ft_strcpy.c \
		ft_strcmp.c \
		ft_write.c \
		ft_read.c \
		ft_strdup.c 
		
TESTER = $(addprefix $(TESTER_DIR)/, $(TESTER_FILES))


# Enlever .c pour créer les noms des exécutables
ALL_FILES = $(TESTER) \
			tester/main.c \

PMANDATORY =  $(addprefix , $(ALL_FILES))
M_OBJS = $(PMANDATORY:$(SRC_DIR)%.c=$(OBJ_DIR)/%.o)

#COLOR SET
COLOR_RESET = \e[0m
COLOR_RED = \e[31m
COLOR_GREEN = \e[32m
COLOR_BLUE = \e[34m


all: $(NAME)

$(OBJ_DIR)/%.o :  $(SRC_DIR)%.c 
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(M_OBJS)
	@make -s -C libasm
	@$(CC) $(CFLAGS) $(M_OBJS) -o $(NAME) $(LIBASM)

clean:
	@make -s -C libasm clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make -s -C libasm fclean
	@rm -f $(NAME)

re: fclean all


.PHONY: all clean fclean re 