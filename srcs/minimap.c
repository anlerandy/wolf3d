/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 10:51:51 by acourtin          #+#    #+#             */
/*   Updated: 2018/02/21 12:10:04 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		draw_player(t_data *data, double x, double y)
{
	int i;
	int j;

	j = -1;
	x += 1;
	y += 1;
	while (++j < 3)
	{
		i = -1;
		while (++i < 3)
		{
			((int*)data->minimap.img)[((int)x * 3 + i) + (((int)y * 3 + j) \
				* 300)] = 0x00FF0000;
		}
	}
}

static void		draw_cube(t_data *data, int x, int y)
{
	int i;
	int j;

	j = -1;
	while (++j < 4)
	{
		i = -1;
		while (++i < 4)
		{
			((int*)data->minimap.img)[x * 4 + i + ((y * 4 + j) \
				* 300)] = (data->map.tiles[y][x].z * 0x00111111) + 0x00555555;
		}
	}
}

void			draw_minimap(t_data *data)
{
	int i;
	int j;

	j = -1;
	data->minimap.img = ft_intset(data->minimap.img, 0x00000000, 300 * 300);
	while (++j < data->map.h)
	{
		i = -1;
		while (++i < data->map.w)
		{
			draw_cube(data, i, j);
		}
	}
	draw_player(data, data->player.pos.x, data->player.pos.y);
}
