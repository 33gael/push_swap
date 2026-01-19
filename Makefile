# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gaeducas <gaeducas@student.fr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/13 11:36:41 by gaeducas          #+#    #+#              #
#    Updated: 2026/01/19 14:13:38 by gaeducas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -Iincludes
RM          = rm -rf

PRINTF_DIR  = includes/ft_printf
PRINTF      = $(PRINTF_DIR)/libftprintf.a

SRC_DIR     = src
OBJ_DIR     = obj

SRCS        = $(SRC_DIR)/push_swap.c \
              $(SRC_DIR)/parsing.c \
              $(SRC_DIR)/stack_init.c \
              $(SRC_DIR)/ft_utils.c \
              $(SRC_DIR)/utils.c \
              $(SRC_DIR)/push.c \
              $(SRC_DIR)/swap.c \
              $(SRC_DIR)/rotate.c \
              $(SRC_DIR)/rev_rotate.c \
              $(SRC_DIR)/lil_sort.c \
              $(SRC_DIR)/butterfly.c \
              $(SRC_DIR)/indexing.c

OBJS        = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

GREEN       = \033[0;32m
YELLOW      = \033[0;33m
RESET       = \033[0m

all: $(NAME)

$(NAME): $(PRINTF) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -L$(PRINTF_DIR) -lftprintf -o $(NAME)
	@echo "$(GREEN)Push_swap compiled successfully!$(RESET)"

$(PRINTF):
	@make -s -C $(PRINTF_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ_DIR)
	@make -s -C $(PRINTF_DIR) clean
	@echo "$(YELLOW)Objects cleaned.$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@make -s -C $(PRINTF_DIR) fclean
	@echo "$(YELLOW)Executables cleaned.$(RESET)"

re: fclean all

.PHONY: all clean fclean re
