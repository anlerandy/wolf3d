/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 21:25:30 by alerandy          #+#    #+#             */
/*   Updated: 2018/03/06 19:43:04 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		init_player(t_data *data)
{
	int i;

	i = -1;
	debug(data->debug, "Initialisation de PLAYER.");
	data->player.hp = 100;
	data->player.end = 100;
	data->player.amo = 60;
	data->player.amo_chamber = 1;
	data->player.fired = 0;
	data->player.reloading = 0;
	data->player.is_moving = 0;
	data->player.gun_frame = 0;
	data->player.rotx = 0.0;
	data->player.roty = 0.0;
	while (++i < data->win_w)
	{
		data->player.r[i].x = 0;
		data->player.r[i].y = 0;
	}
}

static void	begin_anim(t_data *data, int maxframe, float *timer)
{
	*timer += GUN_ANIM;
	if (*timer >= 10)
	{
		*timer = 0;
		data->player.gun_frame++;
		if (data->player.gun_frame == maxframe)
		{
			data->player.gun_frame = 0;
			data->player.fired = 0;
			data->player.reloading = 0;
		}
	}
}

static void	loop_gun(t_data *data)
{
	static float	timer = 0;

	if (data->player.k_val.fire == 1 && data->player.fired == 0 \
			&& data->player.reloading == 0 && data->player.amo_chamber == 1)
	{
		data->player.fired = 1;
		data->player.gun_frame++;
		data->player.amo_chamber = 0;
	}
	else if (data->player.fired == 1 && data->player.gun_frame <= 4)
		begin_anim(data, 3, &timer);
	else if (data->player.k_val.reload == 1 && data->player.fired == 0 \
			&& data->player.reloading == 0 && data->player.amo >= 2 \
			&& data->player.amo_chamber == 0)
	{
		data->player.reloading = 1;
		data->player.gun_frame = 4;
		data->player.amo_chamber = 1;
	}
	else if (data->player.reloading == 1 && data->player.gun_frame <= 13)
		begin_anim(data, 14, &timer);
}

void		loop_player(t_data *data)
{
	int			i;

	i = -1;
	data->player.rotx = cos((data->player.rot / 180) * M_PI);
	data->player.roty = sin((data->player.rot / 180) * M_PI);
	create_threads(data);
	loop_gun(data);
}

int			move_player(t_data *data, int d)
{
	int		x;
	int		y;
	int		res;
	double	speed;

	speed = PLAYER_SPEED;
	res = 0;
	x = floor(data->player.pos.x + (data->player.rotx * 10) * speed * d);
	y = floor(data->player.pos.y + (data->player.roty * 10) * speed * d);
	data->player.is_moving = 0;
	if (y < data->map.h && y >= 0 && x < data->map.w && x >= 0)
	{
		if (data->map.tiles[y][(int)(data->player.pos.x)].z != 9)
		{
			data->player.pos.y += data->player.roty * PLAYER_SPEED * d;
			data->player.is_moving = 1;
			res = 1;
		}
		if (data->map.tiles[(int)(data->player.pos.y)][x].z != 9)
		{
			data->player.pos.x += data->player.rotx * PLAYER_SPEED * d;
			data->player.is_moving = 1;
			res = 1;
		}
	}
	return (res);
}
