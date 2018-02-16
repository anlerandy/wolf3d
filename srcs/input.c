/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 01:37:02 by alerandy          #+#    #+#             */
/*   Updated: 2018/02/16 06:20:15 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		press(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	key == KEY_ESCAPE ? usage(42) : key;
	if ((key == KEY_UP || key == KEY_DOWN) && data->intro.fin == 1)
	{
		data->menu.selection += (key == KEY_UP) * -1 + (key == KEY_DOWN) * 1;
		if (data->menu.selection < 0)
			data->menu.selection = 8;
		else if (data->menu.selection > 8)
			data->menu.selection = 0;
	}
	else if (key == KEY_ENTER && data->intro.fin == 1)
		execute_menu(data);
	else if (key == KEY_F10)
	{
		data->debug = !data->debug ? 1 : 0;
		data->debug ? ft_putendl("Debug Activé.") :
			ft_putendl("Debug désactivé");
	}
	key ? data->flag = 255 + 1 : key;
	key && !data->intro.auth ? skip_to_menu(data) : key;
	return (0);
}

int		release(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	(void)key;
	return (0);
}
