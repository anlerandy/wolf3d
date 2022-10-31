/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 01:37:02 by alerandy          #+#    #+#             */
/*   Updated: 2021/11/17 14:39:44 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	menu_choice(int key, t_data *data)
{
	if (data->game_state == MENU && !data->loading)
	{
		data->menu.selection += -(key == 65362) + (key == 65364);
		data->menu.selection == 7 ? data->menu.selection = 0 : key;
		data->menu.selection == -1 ? data->menu.selection = 6 : key;
	}
	if ((data->game_state == GAME || data->game_state == PAUSE) && key == 112
	&& data->loading != 3)
	{
		data->game_state = (data->game_state == GAME ? PAUSE : GAME);
		data->game_state == PAUSE ? data->menu.selection = 0 : key;
	}
	if (data->game_state == PAUSE && !data->loading)
	{
		data->menu.selection += -(key == 65362) + (key == 65364);
		data->menu.selection == 4 ? data->menu.selection = 0 : key;
		data->menu.selection == -1 ? data->menu.selection = 3 : key;
	}
	if (key == 65293 && data->game_state == PAUSE)
		execute_pause(data);
	// key == 112AD_ADD && data->player.hp < 100 ? data->player.hp++ : key;
	// key == 112AD_MULTIPLY && data->player.hp < 91 ? data->player.hp += 10 :
	// 	key;
	// key == 112AD_SUB && data->player.hp > 0 ? data->player.hp-- : key;
	// key == 112AD_DIVIDE && data->player.hp > 10 ? data->player.hp -= 10 : key;
}

int		press(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	data->intro.fin ? menu_choice(key, data) : key;
	key == 65307 ? usage(42) : key;
	if (data->game_state == GAME)
		ft_player_input(data, key, 1);
	if (key == 65293 && data->intro.fin == 1 && data->game_state == MENU \
			&& !data->loading)
		execute_menu(data);
	if (key == 65479 || key == 96)
		data->debug = !data->debug ? 1 : 0;
	key ? data->flag = 255 + 1 : key;
	key && !data->intro.auth ? skip_to_menu(data) : key;
	data->game_state == INPUT && key == 112 ? data->game_state = PAUSE : 0;
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
