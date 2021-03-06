/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 10:51:51 by acourtin          #+#    #+#             */
/*   Updated: 2018/03/02 17:27:43 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		draw_player(t_data *data, double x, double y)
{
	int i;

	i = -1;
	while (++i < 3 * 3)
	{
		((int*)data->minimap.img)[((int)((x - 1.25) * 4 + (i % 3))) \
			+ (((int)((y - 1.25) * 4 + (i / 3))) * 300)] = 0x00FF0000;
		if (!data->debug)
			((int*)data->minimap.img)[((int)((x - 1.25) * 4 + (i % 3))) +
				(((int)((y - 1.25) * 4 + (i / 3))) * 300)] +=
				MINI_OPAC & 0xFF000000;
	}
	i = -1;
	if (!data->debug)
		while (++i < 3 * 3)
			((int*)data->minimap.img)[((int)((x - 1.25 + data->player.rotx) \
				* 4 + (i % 3))) + (((int)((y - 1.25 + data->player.roty) * 4 \
				+ (i / 3))) * 300)] = 0x0000FF00 + MINI_OPAC;
}

static void		draw_cube(t_data *data, int x, int y)
{
	int			i;

	i = -1;
	while (++i < 4 * 4)
	{
		((int*)data->minimap.img)[x * 4 + (i % 4) + ((y * 4 + (i / 4)) \
			* 300)] = (data->map.tiles[y][x].z * 0x00111111) + 0x00555555;
		if (!data->debug)
			((int*)data->minimap.img)[x * 4 + (i % 4) + ((y * 4 + (i / 4)) \
				* 300)] += MINI_OPAC & 0xFF000000;
	}
}

void			draw_minimap(t_data *data)
{
	int i;

	i = -1;
	data->minimap.img = ft_intset(data->minimap.img, 0xFF000000, 300 * 300);
	while (++i < data->map.h * data->map.w)
		draw_cube(data, i % data->map.w, i / data->map.w);
	if (data->debug == 1)
	{
		i = -1;
		while (++i < 300 * 300)
		{
			if ((i / 300) % 4 == 0 || (i % 300) % 4 == 0)
				((int*)data->minimap.img)[i] = 0x00000000;
		}
	}
	draw_player(data, data->player.pos.x + 1.0, data->player.pos.y + 1.0);
}
