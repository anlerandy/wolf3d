/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 21:25:30 by alerandy          #+#    #+#             */
/*   Updated: 2018/02/22 20:33:34 by acourtin         ###   ########.fr       */
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
	data->player.rot = 90.0;
	data->player.rotx = 0.0;
	data->player.roty = 0.0;
	while (++i < data->win_w)
	{
		data->player.r[i].x = 0;
		data->player.r[i].y = 0;
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
	if (data->player.pos.x > 95)
		data->player.pos.x = 95;
	if (data->player.pos.y > 95)
		data->player.pos.y = 95;
	data->player.rotx = sin((data->player.rot / 180) * M_PI);
	data->player.roty = cos((data->player.rot / 180) * M_PI);
	while (++i < data->win_w)
	{
		rotx = sin(((data->player.rot + (i * 0.06) - 45) / 180) * M_PI);
		roty = cos(((data->player.rot + (i * 0.06) - 45) / 180) * M_PI);
		data->player.r[i].x = data->player.pos.x + (rotx * 4);
		data->player.r[i].y = data->player.pos.y + (roty * 4);
	}
}

void		move_player(t_data *data, int d)
{
	data->player.pos.x += data->player.rotx * PLAYER_SPEED * d;
	data->player.pos.y += data->player.roty * PLAYER_SPEED * d;
}
