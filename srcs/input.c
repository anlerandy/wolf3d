/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 01:37:02 by alerandy          #+#    #+#             */
/*   Updated: 2018/03/05 08:10:39 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	menu_choice(int key, t_data *data)
{
	if (data->game_state == MENU && !data->loading)
	{
		data->menu.selection += -(key == KEY_UP) + (key == KEY_DOWN);
		data->menu.selection == 7 ? data->menu.selection = 0 : key;
		data->menu.selection == -1 ? data->menu.selection = 6 : key;
	}
	if ((data->game_state == GAME || data->game_state == PAUSE) && key == KEY_P
	&& data->loading != 3)
	{
		data->game_state = (data->game_state == GAME ? PAUSE : GAME);
		data->game_state == PAUSE ? data->menu.selection = 0 : key;
	}
	if (data->game_state == PAUSE)
	{
		data->menu.selection += -(key == KEY_UP) + (key == KEY_DOWN);
		data->menu.selection == 4 ? data->menu.selection = 0 : key;
		data->menu.selection == -1 ? data->menu.selection = 3 : key;
	}
	if (key == KEY_ENTER && data->game_state == PAUSE)
		execute_pause(data);
	key == KEY_PAD_ADD && data->player.hp < 100 ? data->player.hp++ : key;
	key == KEY_PAD_MULTIPLY && data->player.hp < 91 ? data->player.hp += 10 :
		key;
	key == KEY_PAD_SUB && data->player.hp > 0 ? data->player.hp-- : key;
	key == KEY_PAD_DIVIDE && data->player.hp > 10 ? data->player.hp -= 10 : key;
}

int		press(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	data->intro.fin ? menu_choice(key, data) : key;
	key == KEY_ESCAPE ? usage(42) : key;
	if (data->game_state == GAME)
		ft_player_input(data, key, 1);
	if (key == KEY_ENTER && data->intro.fin == 1 && data->game_state == MENU)
		execute_menu(data);
	if (key == KEY_F10 || key == KEY_TILDE)
		data->debug = !data->debug ? 1 : 0;
	key ? data->flag = 255 + 1 : key;
	key && !data->intro.auth ? skip_to_menu(data) : key;
	data->game_state == INPUT && key == KEY_P ? data->game_state = PAUSE : 0;
	return (0);
}

int		release(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (data->game_state == GAME)
		ft_player_input(data, key, 0);
	return (0);
}
