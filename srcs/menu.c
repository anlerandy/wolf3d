/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 03:31:25 by acourtin          #+#    #+#             */
/*   Updated: 2018/02/27 16:27:04 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void			rebuild_menu(t_data *data)
{
	static t_xpm	menu;
	static int		x = 0;

	map_clear(data);
	debug(data->debug, "Refonte du menu.");
	data->game_state = MENU;
	data->menu.selection = 0;
	if (!x)
		menu = xpm_create(data, "./xpm/menu.xpm", 1400, 800);
	x = 1;
	xpm_draw(data, menu);
}

void			init_menu(t_data *data)
{
	debug(data->debug, "Initialisation du menu");
	data->menu.selection = 0;
}

void			draw_menu(t_data *data)
{
	data->tmp.img = ft_intset(data->tmp.img, 0xff000000,
			data->win_h * data->win_w);
	ft_type(data, ">", 560, 300 + 50 * data->menu.selection);
	ft_type(data, "MAP1", 600 + (25 * (data->menu.selection == 0)), 300);
	ft_type(data, "MAP2", 600 + (25 * (data->menu.selection == 1)), 350);
	ft_type(data, "MAP3", 600 + (25 * (data->menu.selection == 2)), 400);
	ft_type(data, "MAP4", 600 + (25 * (data->menu.selection == 3)), 450);
	ft_type(data, "MAP5", 600 + (25 * (data->menu.selection == 4)), 500);
	ft_type(data, "QUITTER", 600 + (25 * (data->menu.selection == 5)), 550);
//	ft_type(data, "MAP6", 600 + (25 * (data->menu.selection == 5)), 550);
//	ft_type(data, "MAP7", 600 + (25 * (data->menu.selection == 6)), 600);
//	ft_type(data, "MAP8", 600 + (25 * (data->menu.selection == 7)), 650);
//	ft_type(data, "MAP9", 600 + (25 * (data->menu.selection == 8)), 700);
	mlx_put_image_to_window(data->mlx, data->win, data->tmp.pimg, 0, 0);
}

void			execute_menu(t_data *data)
{
	if (data->menu.selection == 5)
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
	xpm_draw(data, intr);
	data->intro.launched = 2;
	data->intro.qd = 1;
	data->intro.auth = 1;
	data->intro.fin = 1;
}
