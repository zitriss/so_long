# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlize <tlize@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/13 15:12:54 by tlize             #+#    #+#              #
#    Updated: 2025/04/13 14:54:15 by tlize            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR = src
OBJ_DIR = obj

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra

# == Couleurs pour les messages dans le terminal ==
YELLOW = \033[1;33m
NC = \033[0m

all:		$(NAME)

# == Construction de la bibliothèque statique ==
$(NAME):	$(OBJS)
			ar rsc $(NAME) $(OBJS)
			@echo "$(YELLOW)libft.a created successfully!$(NC)"

# == Compilation des fichiers .c en .o ==
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# == Nettoyage des fichiers objets ==
clean:
			rm -f $(OBJS)
			@echo "$(YELLOW)Object files cleaned.$(NC)"

# == Nettoyage complet ==
fclean:		clean
			rm -f $(NAME)
			@echo "$(YELLOW)Library removed.$(NC)"

# == Recompilation complète ==
re:		fclean all

.PHONY:		all clean fclean re
