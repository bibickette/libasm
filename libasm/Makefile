# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phwang <phwang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/25 23:59:26 by phwang            #+#    #+#              #
#    Updated: 2026/02/27 16:20:36 by phwang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libasm.a

NASM = nasm
NASM_FLAGS = -f elf64 -g

# Source directories
SRC_DIR = src/
OBJ_DIR = obj

#SRC FILES
SRC_FILES = \
		ft_strlen.s

ALL_FILES =  $(addprefix $(SRC_DIR), $(SRC_FILES))
ALL_OBJS = $(ALL_FILES:$(SRC_DIR)%.s=$(OBJ_DIR)/%.o)


all:$(NAME)

$(OBJ_DIR)/%.o : $(SRC_DIR)%.s 
	@mkdir -p $(dir $@)
	$(NASM) $(NASM_FLAGS) $< -o $@


$(NAME) : $(ALL_OBJS)
	@ar -rcs $(NAME) $(ALL_OBJS)


clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re try