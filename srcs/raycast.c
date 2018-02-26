/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 20:44:58 by acourtin          #+#    #+#             */
/*   Updated: 2018/02/26 20:45:54 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		loop_ray(t_data *data, t_ray *r, double rotx, double roty)
{
	if (data->debug)
		((int*)data->minimap.img)[(int)((r->x * 4)) \
			+ ((int)((r->y * 4)) * 300)] = 0x0000FF00;
	r->x += (rotx) / DPI_FAC;
	r->y += (roty) / DPI_FAC;
	r->depth += 1 / DPI_FAC;
}

static int		check_z(t_data *data, t_ray *r, double rotx, double roty)
{
	if (data->map.tiles[(int)(r->y)][(int)(r->x)].z > 0)
		return (1);
	return (0);
}

void			send_ray(t_data *data, t_ray *r, double rotx, double roty)
{
	r->x = data->player.pos.x;
	r->y = data->player.pos.y;
	r->depth = 0;
	loop_ray(data, r, rotx, roty);
	while ((r->x > 0 && r->x < 99 && r->y > 0 && r->y < 99) \
			&& check_z(data, r, rotx, roty) == 0)
		loop_ray(data, r, rotx, roty);
	r->x < 0 ? r->x = 0 : 0;
	r->y < 0 ? r->y = 0 : 0;
	r->x > 99 ? r->x = 99 : 0;
	r->y > 99 ? r->y = 99 : 0;
}
