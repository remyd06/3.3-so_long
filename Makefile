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

INCDIR = include
MLXDIR = minilibx-linux

SRCS =	src/main.c \
		src/map/map_init.c \
		src/map/map_parsing.c \
		utils/count_char_occurences_in_array.c \
		utils/free_map.c \
		utils/ft_putnbr.c \
		utils/ft_putstr.c \
		utils/ft_strerror.c \
		utils/get_next_line.c \
		utils/get_next_line_utils.c \
		src/game/init_game.c \
		src/game/load_assets.c \
		src/game/print_assets/print_wall.c \
		src/game/print_assets/print_ground.c \
		src/game/print_assets/print_item.c \
		src/game/print_assets/print_exit.c \
		src/game/print_assets/print_player.c \
		src/movements/close_window.c \
		src/movements/handle_keypress.c \
		src/movements/player_move.c \
		src/map/map_pathfinder.c \

OBJS = ${SRCS:%.c=obj/%.o}

CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3 -std=c11 -I$(INCDIR) -I$(MLXDIR)
LDFLAGS = -L$(MLXDIR) -lmlx -lXext -lX11 -lm

RM = rm -f

DEF_COLOR = \033[0;39m
COLOR = \033[1;32m

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C $(MLXDIR)
	@${CC} ${CFLAGS} ${OBJS} -L${MLXDIR} -lmlx -lX11 -lXext -lm -o ${NAME}
	@echo "$(COLOR)╔═══════════════════════╗$(DEF_COLOR)"
	@echo "$(COLOR)║   so_long compiled!   ║$(DEF_COLOR)"
	@echo "$(COLOR)╚═══════════════════════╝$(DEF_COLOR)"

obj/%.o:	%.c
			@mkdir -p obj/$(dir $<)
			@${CC} ${CFLAGS} -c $< -o $@

clean:
	@$(MAKE) -C $(MLXDIR) clean
	@$(RM) $(OBJS)
	@echo "$(COLOR)╔═══════════════════════╗$(DEF_COLOR)"
	@echo "$(COLOR)║   so_long cleaned!    ║$(DEF_COLOR)"
	@echo "$(COLOR)╚═══════════════════════╝$(DEF_COLOR)"

fclean: clean
	@$(RM) $(NAME)
	@rm -rf obj
	@echo "$(COLOR)╔═══════════════════════╗$(DEF_COLOR)"
	@echo "$(COLOR)║  Executable removed!  ║$(DEF_COLOR)"
	@echo "$(COLOR)╚═══════════════════════╝$(DEF_COLOR)"

re: fclean all

.PHONY: all clean fclean re

