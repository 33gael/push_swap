# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gaeducas <gaeducas@student.fr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/13 11:36:41 by gaeducas          #+#    #+#              #
#    Updated: 2026/01/19 09:57:53 by gaeducas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -Iincludes
RM          = rm -rf

LIB_DIR     = includes
PRINTF      = $(LIB_DIR)/ft_printf/libftprintf.a

INCS        = -Iincludes -I$(LIB_DIR)/ft_printf

LDFLAGS     = -L$(LIB_DIR)/ft_printf -lftprintf

SRC_DIR     = src
OBJ_DIR     = obj

SRCS        = $(wildcard $(SRC_DIR)/*.c)
OBJS        = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

GREEN       = \033[0;32m
YELLOW      = \033[0;33m
RESET       = \033[0m

all: $(NAME)

$(NAME): $(PRINTF) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)
	@echo "$(GREEN)✓ Push_swap created !$(RESET)"

$(PRINTF):
	@echo "$(YELLOW)ft_printf compilation...$(RESET)"
	@make -s -C $(LIB_DIR)/ft_printf

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCS) -c $< -o $@

clean:
	@$(RM) $(OBJ_DIR)
	@make -s -C $(LIB_DIR)/ft_printf clean
	@echo "$(YELLOW)Objects deleted.$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@make -s -C $(LIB_DIR)/ft_printf fclean
	@echo "$(YELLOW)Everything cleaned.$(RESET)"

re: fclean all

.PHONY: all clean fclean re