# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlize <tlize@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/13 15:12:54 by tlize             #+#    #+#              #
#    Updated: 2025/04/13 15:17:41 by tlize            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR = src
GNL_DIR = $(SRC_DIR)/gnl
OBJ_DIR = obj
INC_DIR = includes


SRCS = $(wildcard $(SRC_DIR)/*.c) $(wildcard $(GNL_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(wildcard $(SRC_DIR)/*.c)) \
	   $(patsubst $(GNL_DIR)/%.c, $(OBJ_DIR)/gnl_%.o, $(wildcard $(GNL_DIR)/*.c))



NAME = libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra -I$(INC_DIR)

# == Couleurs pour les messages dans le terminal ==
YELLOW = \033[1;33m
NC = \033[0m

all:		$(NAME)

$(NAME):	$(OBJS)
			ar rsc $(NAME) $(OBJS)
			@echo "$(YELLOW)libft.a created successfully!$(NC)"

# == Compilation des fichiers .c en .o ==
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/gnl_%.o: $(GNL_DIR)/%.c | $(OBJ_DIR)
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
