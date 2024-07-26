# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdedola <rdedola@student.42nice.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/21 17:19:03 by rdedola           #+#    #+#              #
#    Updated: 2024/07/21 17:19:03 by rdedola          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCDIR = src
INCDIR = include
MLXDIR = minilibx-linux

SRCS = $(SRCDIR)/main.c $(SRCDIR)/map.c $(SRCDIR)/player.c $(SRCDIR)/render.c $(SRCDIR)/utils.c
OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11 -I$(INCDIR) -I$(MLXDIR)
LDFLAGS = -L$(MLXDIR) -lmlx -lXext -lX11 -lm

RM = rm -f

DEF_COLOR = \033[0;39m
COLOR = \033[1;32m

all: $(NAME)

$(SRCDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(COLOR)$<      ✓$(DEF_COLOR)"

$(NAME): $(OBJS)
	@$(MAKE) -C $(MLXDIR)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LDFLAGS)
	@echo "$(COLOR)╔═══════════════════════╗$(DEF_COLOR)"
	@echo "$(COLOR)║   so_long compiled!   ║$(DEF_COLOR)"
	@echo "$(COLOR)╚═══════════════════════╝$(DEF_COLOR)"

clean:
	@$(MAKE) -C $(MLXDIR) clean
	@$(RM) $(OBJS)
	@echo "$(COLOR)╔═══════════════════════╗$(DEF_COLOR)"
	@echo "$(COLOR)║   so_long cleaned!    ║$(DEF_COLOR)"
	@echo "$(COLOR)╚═══════════════════════╝$(DEF_COLOR)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(COLOR)╔═══════════════════════╗$(DEF_COLOR)"
	@echo "$(COLOR)║  Executable removed!  ║$(DEF_COLOR)"
	@echo "$(COLOR)╚═══════════════════════╝$(DEF_COLOR)"

re: fclean all

.PHONY: all clean fclean re
