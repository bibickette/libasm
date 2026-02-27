# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phwang <phwang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/25 23:59:26 by phwang            #+#    #+#              #
#    Updated: 2026/02/27 01:27:34 by phwang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libasm
NAME_TRY = test

LINKER = cc
LINKER_FLAGS = -Wall -Wextra -Werror -g3

COMPILER = nasm
COMPILER_FLAGS = -f elf64 -g

# Source directories
SRC_DIR = src/
OBJ_DIR = obj

#SRC FILES
SRC_FILES = \
		ft_strlen.s \
		main.s

ALL_FILES =  $(addprefix $(SRC_DIR), $(SRC_FILES))
ALL_OBJS = $(ALL_FILES:$(SRC_DIR)%.s=$(OBJ_DIR)/%.o)



TRY_DIR = try/
OBJ_TRY_DIR = obj_try

#SRC FILES
TRYSRC_DIR = $(TRY_DIR)src
TRYSRC_FILES = \
		ft_strlen.s \
		ft_strcpy.s 
TRYSRC = $(addprefix $(TRYSRC_DIR)/, $(TRYSRC_FILES))

TRYSRC_ALL_FILES = \
		$(TRYSRC) \
		$(TRY_DIR)main.c

TRY_SRCS  = $(addprefix , $(TRYSRC_ALL_FILES))
TRY_OBJS = $(TRY_SRCS:$(TRY_DIR)%.s=$(OBJ_TRY_DIR)/%.o)


all: $(NAME_TRY) 

$(OBJ_TRY_DIR)/%.o : $(TRY_DIR)%.s 
	@mkdir -p $(dir $@)
	$(COMPILER) $(COMPILER_FLAGS) $< -o $@

$(NAME_TRY) : $(TRY_OBJS)
	$(LINKER) $(LINKER_FLAGS) $(TRY_OBJS) -o $(NAME_TRY)

lib: $(NAME)

$(OBJ_DIR)/%.o : $(SRC_DIR)%.s 
	@mkdir -p $(dir $@)
	$(COMPILER) $(COMPILER_FLAGS) $< -o $@


$(NAME) : $(ALL_OBJS)
	$(LINKER) $(LINKER_FLAGS) $(ALL_OBJS) -o $(NAME)




clean:
	@rm -rf $(OBJ_DIR) $(OBJ_TRY_DIR)

fclean: clean
	@rm -f $(NAME) $(NAME_TRY)

re: fclean all

.PHONY: all clean fclean re try