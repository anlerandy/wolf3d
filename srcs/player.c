/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 21:25:30 by alerandy          #+#    #+#             */
/*   Updated: 2018/02/23 16:09:27 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		init_player(t_data *data)
{
	int i;

	i = -1;
	debug(data->debug, "Initialisation de PLAYER.");
	if (data->player.pos.z == -42)
		usage(5);
	data->player.hp = 100;
	data->player.end = 100;
	data->player.amo = 10;
	data->player.rot = 90.0;
	data->player.rotx = 0.0;
	data->player.roty = 0.0;
	while (++i < data->win_w)
	{
		data->player.r[i].x = 0;
		data->player.r[i].y = 0;
	}
}

void		draw_wall(t_data *data, t_ray ray, int slice)
{
	t_ray	dist;
	int		i;
	int		j;
	double	height;

	dist.x = fabs(data->player.pos.x - ray.x);
	dist.x = fabs(data->player.pos.y - ray.y);
//	height = sqrt(dist.x * dist.x + dist.y + dist.y);
	height = fabs(dist.x - dist.y);
	i = -1;
	j = 0;
	while (floor((data->win_h / 2) - (data->win_h / 4) * height) > ++i)
	{
//		if (height < 10)
			((int*)(data->frame.img))[slice + (i + data->win_h / 2) * data->win_w] = 0xffffff;
			((int*)(data->frame.img))[slice + ((data->win_h / 2) + --j) * data->win_w] = 0xffffff;
	}
}

void		loop_player(t_data *data)
{
	int		i;
	double	rotx;
	double	roty;

	i = -1;
	if (data->player.pos.x < 0)
		data->player.pos.x = 0;
	if (data->player.pos.y < 0)
		data->player.pos.y = 0;
	if (data->player.pos.x > 97.5)
		data->player.pos.x = 97.5;
	if (data->player.pos.y > 97.5)
		data->player.pos.y = 97.5;
	data->player.rotx = sin((data->player.rot / 180) * M_PI);
	data->player.roty = cos((data->player.rot / 180) * M_PI);
	while (++i < data->win_w)
	{
		send_ray(data, &data->player.r[i], sin(((data->player.rot + (i * 0.06) \
			- 45) / 180) * M_PI), cos(((data->player.rot + (i * 0.06) - 45) \
			/ 180) * M_PI));
		draw_wall(data, data->player.r[i], i);
	}
}

void		move_player(t_data *data, int d)
{
	int		x;
	int		y;

	x = floor(data->player.pos.x + data->player.rotx * PLAYER_SPEED * d);
	y = floor(data->player.pos.y + data->player.roty * PLAYER_SPEED * d);
//	La minimap fonctionne en case de 3 : Cette protection semble fonctionner.
//	if (data->map.tiles[y][x].z != 9)
//	{
		data->player.pos.x += data->player.rotx * PLAYER_SPEED * d;
		data->player.pos.y += data->player.roty * PLAYER_SPEED * d;
//	}
}
