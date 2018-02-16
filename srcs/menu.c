/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 03:31:25 by acourtin          #+#    #+#             */
/*   Updated: 2018/02/16 04:34:46 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void			init_menu(t_data *data)
{
	debug(data->debug, "Initialisation du menu");
	data->menu.selection = 1;
}

void			draw_menu(t_data *data)
{
	mlx_string_put(data->mlx, data->win, 625, 400, 0x00FFFFFF, \
		"/// NOM DU JEU \\\\\\");
	if (data->menu.selection == 1)
	{
		mlx_string_put(data->mlx, data->win, 650, 450, 0x00FF0505, "PLAY");
		mlx_string_put(data->mlx, data->win, 650, 475, 0x00FFFFFF, "QUIT");
	}
	else
	{
		mlx_string_put(data->mlx, data->win, 650, 450, 0x00FFFFFF, "PLAY");
		mlx_string_put(data->mlx, data->win, 650, 475, 0x00FF0505, "QUIT");
	}
}

void			execute_menu(t_data *data)
{
	if (data->menu.selection == 1)
	{
		// PLAY
	}
	else
		usage(42);
}
