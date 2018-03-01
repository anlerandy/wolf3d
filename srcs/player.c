/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 21:25:30 by alerandy          #+#    #+#             */
/*   Updated: 2018/03/01 06:13:43 by alerandy         ###   ########.fr       */
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
	data->player.fired = 0;
	data->player.gun_frame = 0;
	data->player.rot = 0;
	data->player.rotx = 0.0;
	data->player.roty = 0.0;
	while (++i < data->win_w)
	{
		data->player.r[i].x = 0;
		data->player.r[i].y = 0;
	}
}

static void	loop_gun(t_data *data)
{
	static float	timer = 0;


	if (data->player.k_val.fire == 1 && data->player.amo > 0 && data->player.fired == 0)
	{
		data->player.amo--;
		data->player.fired = 1;
		data->player.gun_frame++;
	}
	else if (data->player.fired == 1 && data->player.gun_frame <= 12)
	{
		timer += GUN_ANIM;
		if (timer >= 10)
		{
			timer = 0;
			data->player.gun_frame++;
			if (data->player.gun_frame == 13)
			{
				data->player.gun_frame = 0;
				data->player.fired = 0;
			}
		}
	}
}

void		loop_player(t_data *data)
{
	int		i;

	i = -1;
	data->player.pos.x < 0 ? data->player.pos.x = 0 : 0;
	data->player.pos.y < 0 ? data->player.pos.y = 0 : 0;
	data->player.pos.x > 97.5 ? data->player.pos.x = 97.5 : 0;
	data->player.pos.y > 97.5 ? data->player.pos.y = 97.5 : 0;
	data->player.rotx = cos((data->player.rot / 180) * M_PI);
	data->player.roty = sin((data->player.rot / 180) * M_PI);
	while (++i < data->win_w)
	{
		send_ray(data, i);
		draw_wall(data, data->player.r[i], i + 1);
	}
	loop_gun(data);
}

int		move_player(t_data *data, int d)
{
	int		x;
	int		y;

	x = floor(data->player.pos.x + data->player.rotx * PLAYER_SPEED * d);
	y = floor(data->player.pos.y + data->player.roty * PLAYER_SPEED * d);
	if (data->map.tiles[y][x].z != 9
			&& data->map.tiles[y][(int)(data->player.pos.x)].z != 9 \
			&& data->map.tiles[(int)(data->player.pos.y)][x].z != 9)
	{
		data->player.pos.x += data->player.rotx * PLAYER_SPEED * d;
		data->player.pos.y += data->player.roty * PLAYER_SPEED * d;
		return (1);
	}
	return (0);
}
