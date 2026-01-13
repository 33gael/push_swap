# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gaeducas <gaeducas@student.fr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/13 11:36:41 by gaeducas          #+#    #+#              #
#    Updated: 2026/01/13 13:43:17 by gaeducas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap

# --- Compilateur et Flags ---
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -Iincludes
RM          = rm -rf

# --- Dossiers et Bibliothèques ---
LIB_DIR     = includes
LIBFT       = $(LIB_DIR)/libft/libft.a
PRINTF      = $(LIB_DIR)/ft_printf/libftprintf.a

# Inclusion des dossiers de headers pour la compilation
INCS        = -Iincludes -I$(LIB_DIR)/libft -I$(LIB_DIR)/ft_printf

# Flags pour le lien final (LDFLAGS)
LDFLAGS     = -L$(LIB_DIR)/libft -lft -L$(LIB_DIR)/ft_printf -lftprintf

# --- Sources et Objets ---
SRC_DIR     = src
OBJ_DIR     = obj

# Récupération de tous les .c dans le dossier src
SRCS        = $(wildcard $(SRC_DIR)/*.c)
# Transformation des chemins .c en .o dans le dossier obj
OBJS        = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# --- Couleurs ---
GREEN       = \033[0;32m
YELLOW      = \033[0;33m
RESET       = \033[0m

# --- Règles ---

all: $(NAME)

$(NAME): $(LIBFT) $(PRINTF) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)
	@echo "$(GREEN)✓ Push_swap créé avec succès !$(RESET)"

# Règle pour compiler la Libft
$(LIBFT):
	@echo "$(YELLOW)Compilation de la Libft...$(RESET)"
	@make -s -C $(LIB_DIR)/libft

# Règle pour compiler ft_printf
$(PRINTF):
	@echo "$(YELLOW)Compilation de ft_printf...$(RESET)"
	@make -s -C $(LIB_DIR)/ft_printf

# Règle de compilation des fichiers .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCS) -c $< -o $@

clean:
	@$(RM) $(OBJ_DIR)
	@make -s -C $(LIB_DIR)/libft clean
	@make -s -C $(LIB_DIR)/ft_printf clean
	@echo "$(YELLOW)Objets supprimés.$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@make -s -C $(LIB_DIR)/libft fclean
	@make -s -C $(LIB_DIR)/ft_printf fclean
	@echo "$(YELLOW)Nettoyage complet effectué.$(RESET)"

re: fclean all

.PHONY: all clean fclean re