/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 03:31:25 by acourtin          #+#    #+#             */
/*   Updated: 2018/02/16 06:20:45 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void			init_menu(t_data *data)
{
	debug(data->debug, "Initialisation du menu");
	data->menu.selection = 0;
}

void			draw_menu(t_data *data)
{
	mlx_string_put(data->mlx, data->win, 625, 200, 0x00FFFFFF, \
		"/// NOM DU JEU \\\\\\");
	mlx_string_put(data->mlx, data->win, 675, 250, 0x00FFFFFF, "MAP1");
	mlx_string_put(data->mlx, data->win, 675, 275, 0x00FFFFFF, "MAP2");
	mlx_string_put(data->mlx, data->win, 675, 300, 0x00FFFFFF, "MAP3");
	mlx_string_put(data->mlx, data->win, 675, 325, 0x00FFFFFF, "MAP4");
	mlx_string_put(data->mlx, data->win, 675, 350, 0x00FFFFFF, "MAP5");
	mlx_string_put(data->mlx, data->win, 675, 375, 0x00FFFFFF, "MAP6");
	mlx_string_put(data->mlx, data->win, 675, 400, 0x00FFFFFF, "MAP7");
	mlx_string_put(data->mlx, data->win, 675, 425, 0x00FFFFFF, "MAP8");
	mlx_string_put(data->mlx, data->win, 675, 450, 0x00FFFFFF, "QUIT");
	mlx_string_put(data->mlx, data->win, 650, 250 + 25 * data->menu.selection, \
		0x00FF0A0A, ">>");
}

void			execute_menu(t_data *data)
{
	if (data->menu.selection == 8)
		usage(42);
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
