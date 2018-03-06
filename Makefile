# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/13 14:52:44 by alerandy          #+#    #+#              #
#    Updated: 2018/03/06 15:55:02 by alerandy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d
SRC_PATH = srcs/
OBJ_PATH = objects/
SRC_NAME = main.c usage.c debug.c ft_intset.c input.c xpm.c fade_to.c menu.c \
		   pause.c ft_loading.c map.c fill_tiles_steps.c map_clear.c \
		   player.c game.c init_tiles.c minimap.c ft_typo.c raycast.c ath.c \
		   player_input.c world.c time.c gun_anim.c pth_rays.c

OBJ_NAME = $(SRC_NAME:.c=.o)
CC = gcc $(FLAG)
##CC = gcc -g
FLAG = -Wall -Werror -Wextra
FRAME = -framework OpenGL -framework AppKit
LIB = -Lminilibx_macos/ -lmlx -Llibft/ -lft
SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

all : $(NAME)

$(NAME) : libft minilibx $(OBJ)
	@$(CC) $(LIB) $(FRAME) $(OBJ) -o $(NAME)
	@echo "\033[32m/------------------------------------\ \\033[0m"
	@echo "\033[32m|----------- $(NAME) crée ------------| \\033[0m"
	@echo "\033[32m\------------------------------------/ \\033[0m"

libft :
	@$(MAKE) -j -C libft/

minilibx :
	@$(MAKE) -j -C minilibx_macos/

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) -Iminilibx_macos -Iincludes -Ilibft/includes -o $@ -c $<

clean :
	@rm -rf $(OBJ_PATH)
	@$(MAKE) -C minilibx_macos/ clean
	@printf "\033[2A\r\033[K""\033[1;30mLib mlx détruite.\033[0m\n"
	@$(MAKE) -C libft/ clean

fclean :
	@rm -f $(NAME)
	@rm -rf $(OBJ_PATH)
	@$(MAKE) -C minilibx_macos/ clean
	@printf "\033[2A\r\033[K""\033[1;30mLib mlx détruite.\033[0m\n"
	@$(MAKE) -C libft/ fclean
	@rm -f minilibx_macos/libmlx.a

re : fclean $(NAME)
	@printf "\033[\r\033[K""\033[32mLibrairie mlx compilé avec succès.\033[0m\n"

norm :
	@clear
	@norminette srcs/ includes/

norml :
	@clear
	@norminette libft/srcs/ libft/includes/

normall :
	@clear
	@norminette srcs/ includes/
	@norminette libft/srcs/ libft/includes/

.PHONY : fclean clean re norm success minilibx libft norml norm normall all
