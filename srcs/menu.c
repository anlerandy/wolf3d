/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 03:31:25 by acourtin          #+#    #+#             */
/*   Updated: 2018/02/18 03:33:09 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void			rebuild_menu(t_data *data)
{
	static t_xpm	menu;
	static int		x = 0;

	debug(data->debug, "Refonte du menu.");
	data->game_state = MENU;
	data->menu.selection = 0;
	if (!x)
		menu = xpm_create(data, "./xpm/menu2.xpm", 1400, 800);
	x = 1;
	xpm_draw(data, menu, 0, 0);
}

void			init_menu(t_data *data)
{
	debug(data->debug, "Initialisation du menu");
	data->menu.selection = 0;
}

void			draw_menu(t_data *data)
{
	mlx_string_put(data->mlx, data->win, 675 + (25 *
				(data->menu.selection == 0)), 300, 0x00FFFFFF, "MAP1");
	mlx_string_put(data->mlx, data->win, 675 + (25 *
				(data->menu.selection == 1)), 325, 0x00FFFFFF, "MAP2");
	mlx_string_put(data->mlx, data->win, 675 + (25 *
				(data->menu.selection == 2)), 350, 0x00FFFFFF, "MAP3");
	mlx_string_put(data->mlx, data->win, 675 + (25 *
				(data->menu.selection == 3)), 375, 0x00FFFFFF, "MAP4");
	mlx_string_put(data->mlx, data->win, 675 + (25 *
				(data->menu.selection == 4)), 400, 0x00FFFFFF, "MAP5");
	mlx_string_put(data->mlx, data->win, 675 + (25 *
				(data->menu.selection == 5)), 425, 0x00FFFFFF, "MAP6");
	mlx_string_put(data->mlx, data->win, 675 + (25 *
				(data->menu.selection == 6)), 450, 0x00FFFFFF, "MAP7");
	mlx_string_put(data->mlx, data->win, 675 + (25 *
				(data->menu.selection == 7)), 475, 0x00FFFFFF, "MAP8");
	mlx_string_put(data->mlx, data->win, 675 + (25 *
				(data->menu.selection == 8)), 500, 0x00FFFFFF, "QUIT");
	mlx_string_put(data->mlx, data->win, 650, 300 + 25 * data->menu.selection, \
		0x00FF0A0A, ">>");
}

void			execute_menu(t_data *data)
{
	if (data->menu.selection == 8)
		usage(42);
	else
	{
		data->loading = 1;
		loading(data);
	}
}

void			skip_to_menu(t_data *data)
{
	t_xpm intr;

	intr = xpm_create(data, "./xpm/menu.xpm", 1400, 800);
	xpm_draw(data, intr, 0, 0);
	data->intro.launched = 2;
	data->intro.qd = 1;
	data->intro.auth = 1;
	data->intro.fin = 1;
}
