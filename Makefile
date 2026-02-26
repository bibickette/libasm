# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phwang <phwang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/25 23:59:26 by phwang            #+#    #+#              #
#    Updated: 2026/02/26 00:35:53 by phwang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = test

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



all: $(NAME)

$(OBJ_DIR)/%.o : $(SRC_DIR)%.s 
	@mkdir -p $(dir $@)
	$(COMPILER) $(COMPILER_FLAGS) $< -o $@


$(NAME) : $(ALL_OBJS)
	$(LINKER) $(LINKER_FLAGS) $(ALL_OBJS) -o $(NAME)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re