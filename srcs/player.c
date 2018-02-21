/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 21:25:30 by alerandy          #+#    #+#             */
/*   Updated: 2018/02/21 14:05:47 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		init_player(t_data *data)
{
	debug(data->debug, "Initialisation de PLAYER.");
	data->player.hp = 100;
	data->player.end = 100;
	data->player.rot = 90.0;
	data->player.rotx = 0.0;
	data->player.roty = 0.0;
}

void		loop_player(t_data *data)
{
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
}

void		move_player(t_data *data, int d)
{
	data->player.pos.x += data->player.rotx * PLAYER_SPEED * d;
	data->player.pos.y += data->player.roty * PLAYER_SPEED * d;
}
