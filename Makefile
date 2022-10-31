# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/13 14:52:44 by alerandy          #+#    #+#              #
#    Updated: 2021/11/17 14:41:04 by alerandy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d
SRC_PATH = srcs/
OBJ_PATH = objects/
SRC_NAME = main.c usage.c debug.c ft_intset.c input.c xpm.c fade_to.c menu.c \
		   pause.c ft_loading.c map.c fill_tiles_steps.c map_clear.c \
		   player.c game.c init_tiles.c minimap.c ft_typo.c raycast.c ath.c \
		   player_input.c world.c time.c gun_anim.c pth_rays.c malloc_tiles.c \
		   standalone.c

OBJ_NAME = $(SRC_NAME:.c=.o)
CC = gcc $(FLAG)
FLAG = -Wall -Werror -Wextra
SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
LIBSRC = minilibx-linux
LIB = -L$(LIBSRC) -lm -lmlx_Linux -lX11 -lXext -lbsd -Llibft -lft -lpthread
INCLUDES = -Iincludes -Ilibft/includes -I${LIBSRC}

all : $(NAME)

$(NAME) : libft minilibx $(OBJ)
	@$(CC) $(OBJ) $(LIB) -o $(NAME)
	@echo "\033[32m/------------------------------------\ \\033[0m"
	@echo "\033[32m|----------- $(NAME) crée ------------| \\033[0m"
	@echo "\033[32m\------------------------------------/ \\033[0m"

libft :
	@$(MAKE) -j -C libft

minilibx :
	$(MAKE) -s -C $(LIBSRC)

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(INCLUDES) -o $@ -c $<

clean :
	@rm -rf $(OBJ_PATH)
	@$(MAKE) -C ${LIBSRC}/ clean
	@printf "\033[2A\r\033[K""\033[1;30mLib mlx détruite.\033[0m\n"
	@$(MAKE) -C libft/ clean

fclean :
	@rm -f $(NAME)
	@rm -rf $(OBJ_PATH)
	@$(MAKE) -C ${LIBSRC}/ clean
	@printf "\033[2A\r\033[K""\033[1;30mLib mlx détruite.\033[0m\n"
	@$(MAKE) -C libft/ fclean
	@rm -f ${LIBSRC}/libmlx.a
	@rm -rf City42

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

#	La rêgle ci-dessous compile un binaire qui sera mis dans un BOOTABLE DMG.
standalone : re
	@#Supprime city42.dmg si existant.
	@rm -f City42
	@#Nettoie les fichiers désormais inutil.
	@rm -rf $(OBJ_PATH)
	@$(MAKE) -C ${LIBSRC}/ clean
	@$(MAKE) -C libft/ fclean
	@rm -f ${LIBSRC}/libmlx.a
	@#Attribut a ico.png le statut de SELF_icone
	@sips -i xpm/ico.png
	@#Génère une bibliothèque ressource contenant l'icône.
	@Derez -only icns xpm/ico.png > tmpico.rsrc
	@Rez -append tmpico.rsrc -o wolf3d
	@#Attribut au binaire son icône depuis la bibliothèque.
	@SetFile -a C wolf3d
	@#Mis en place des nécessaire pour le DMG.
	@mkdir -p city42
	@cp -r xpm city42/
	@cp -r maps city42/
	@cp wolf3d city42/city42
	@#Création du DMG.
	@hdiutil create -format UDZO -srcfolder city42 City42.dmg
	@#Application de l'icône sur le DMG.
	@Rez -append tmpico.rsrc -o City42.dmg
	@SetFile -a C City42.dmg
	@#Nettoieyage des fichiers désormais inutils.
	@rm tmpico.rsrc
	@rm -rf city42/
	@rm -f wolf3d
	@mv -f City42.dmg City42

.PHONY : fclean clean re norm minilibx libft norml norm normall all standalone
