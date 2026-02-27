# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phwang <phwang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/25 23:59:26 by phwang            #+#    #+#              #
#    Updated: 2026/02/27 16:40:59 by phwang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_TRY = test

LIBASM = libasm/libasm.a


CC = cc
INCLUDE = include
CC_FLAGS = -Wall -Wextra -Werror -g3 -I$(INCLUDE)

NASM = nasm
NASM_FLAGS = -f elf64 -g


TRY_DIR = src/
OBJ_DIR = obj

#SRC FILES
TRYSRC_DIR = $(TRY_DIR)
TRYSRC_FILES = \
		ft_strlen.s \
		ft_strcpy.s 
TRYSRC = $(addprefix $(TRYSRC_DIR)/, $(TRYSRC_FILES))

TRYSRC_ALL_FILES = \
		$(TRYSRC) \
		main.c

TRY_SRCS  = $(addprefix , $(TRYSRC_ALL_FILES))
TRY_OBJS = $(TRY_SRCS:$(TRY_DIR)/%.s=$(OBJ_DIR)/%.o)


all: $(NAME_TRY) 

$(OBJ_DIR)/%.o : $(TRY_DIR)%.s 
	@mkdir -p $(dir $@)
	$(NASM) $(NASM_FLAGS) $< -o $@

$(NAME_TRY) : $(TRY_OBJS)
	$(CC) $(CC_FLAGS) $(TRY_OBJS) -o $(NAME_TRY)


clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME_TRY)

re: fclean all

.PHONY: all clean fclean re try