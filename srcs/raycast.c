/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 20:44:58 by acourtin          #+#    #+#             */
/*   Updated: 2018/02/22 21:48:51 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void			send_ray(t_data *data, int col, double rotx, double roty)
{
	data->player.r[col].x = data->player.pos.x;
	data->player.r[col].y = data->player.pos.y;
	data->player.r[col].x += (rotx * 6);
	data->player.r[col].y += (roty * 6);
	while (data->player.r[col].x - floor(data->player.r[col].x) > 0.1 \
			|| data->player.r[col].x - floor(data->player.r[col].x) < -0.1)
		data->player.r[col].x += 0.01;
	while (data->player.r[col].y - floor(data->player.r[col].y) > 0.1 \
			|| data->player.r[col].y - floor(data->player.r[col].y) < -0.1)
		data->player.r[col].y += 0.01;
	if (data->player.r[col].x < 0)
		data->player.r[col].x = 0;
	if (data->player.r[col].y < 0)
		data->player.r[col].y = 0;
	if (data->player.r[col].x > 99)
		data->player.r[col].x = 99;
	if (data->player.r[col].y > 99)
		data->player.r[col].y = 99;
}
