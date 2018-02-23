/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 20:44:58 by acourtin          #+#    #+#             */
/*   Updated: 2018/02/23 16:06:33 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		loop_ray(t_data *data, t_ray *r, double rotx, double roty)
{
	((int*)data->minimap.img)[(int)((r->x * 3)) + ((int)((r->y * 3)) * 300)] = 0x0000FF00;
	r->x += rotx / 2;
	r->y += roty / 2;
	//r->x = floor(r->x);
	//r->y = floor(r->y);
}

static int		check_z(t_data *data, t_ray *r, double rotx, double roty)
{
	if (data->map.tiles[(int)((r->y / 1.335))][(int)((r->x / 1.335))].z > 0)
		return (1);
	return (0);
}

void			send_ray(t_data *data, t_ray *r, double rotx, double roty)
{
	r->x = data->player.pos.x + 1.0;
	r->y = data->player.pos.y + 1.0;
	while ((r->x > 0 && r->x < 99 && r->y > 0 && r->y < 99) && check_z(data, r, rotx, roty) == 0)
	//while (r->x > 0 && r->x < 100 && r->y > 0 && r->y < 100)
		loop_ray(data, r, rotx, roty);
	if (r->x < 0)
		r->x = 0;
	if (r->y < 0)
		r->y = 0;
	if (r->x > 99)
		r->x = 99;
	if (r->y > 99)
		r->y = 99;
}
