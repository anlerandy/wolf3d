/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 01:37:02 by alerandy          #+#    #+#             */
/*   Updated: 2018/02/18 02:23:59 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	menu_choice(int key, t_data *data)
{
	if (!data->intro.fin)
		return ;
	if (data->game_state == MENU)
	{
		data->menu.selection += -(key == KEY_UP) + (key == KEY_DOWN);
		data->menu.selection == 9 ? data->menu.selection = 0 : key;
		data->menu.selection == -1 ? data->menu.selection = 8 : key;
	}
	if ((data->game_state == GAME || data->game_state == PAUSE) && key == KEY_P)
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
}

int		press(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	key == KEY_ESCAPE ? usage(42) : key;
	if (key == KEY_ENTER && data->intro.fin == 1 && data->game_state == MENU)
		execute_menu(data);
	if (key == KEY_F10)
		data->debug = !data->debug ? 1 : 0;
	key ? data->flag = 255 + 1 : key;
	key && !data->intro.auth ? skip_to_menu(data) : key;
	menu_choice(key, data);
	return (0);
}

int		release(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	(void)key;
	return (0);
}
