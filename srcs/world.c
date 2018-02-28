/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 17:18:38 by acourtin          #+#    #+#             */
/*   Updated: 2018/02/28 16:18:52 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void	color_walls(t_data *data, t_ray ray, int *color)
{
	if (data->map.tiles[(int)(ray.y + 0.02)][(int)ray.x].z == 0 \
			&& data->map.tiles[(int)(ray.y - 0.02)][(int)ray.x].z != 0 \
			&& data->map.tiles[(int)ray.y][(int)(ray.x + 0.02)].z != 0 \
			&& data->map.tiles[(int)ray.y][(int)(ray.x - 0.02)].z != 0)
		*color =  0x00FF0000;
	if (data->map.tiles[(int)(ray.y + 0.02)][(int)ray.x].z != 0 \
			&& data->map.tiles[(int)(ray.y - 0.02)][(int)ray.x].z == 0 \
			&& data->map.tiles[(int)ray.y][(int)(ray.x + 0.02)].z != 0 \
			&& data->map.tiles[(int)ray.y][(int)(ray.x - 0.02)].z != 0)
		*color =  0x000000FF;
	if (data->map.tiles[(int)(ray.y + 0.02)][(int)ray.x].z != 0 \
			&& data->map.tiles[(int)(ray.y - 0.02)][(int)ray.x].z != 0 \
			&& data->map.tiles[(int)ray.y][(int)(ray.x + 0.02)].z == 0 \
			&& data->map.tiles[(int)ray.y][(int)(ray.x - 0.02)].z != 0)
		*color =  0x0000FF00;
	if (data->map.tiles[(int)(ray.y + 0.02)][(int)ray.x].z != 0 \
			&& data->map.tiles[(int)(ray.y - 0.02)][(int)ray.x].z != 0 \
			&& data->map.tiles[(int)ray.y][(int)(ray.x + 0.02)].z != 0 \
			&& data->map.tiles[(int)ray.y][(int)(ray.x - 0.02)].z == 0)
		*color =  0x00FFFF00;
}

void		draw_wall(t_data *data, t_ray ray, int slice)
{
	double	h;
	double	d;
	double	h2;
	t_ray	dist;
	int		color;

	h = 0;
	h2 = 1;
	dist.x = data->player.pos.x - ray.x;
	dist.y = data->player.pos.y - ray.y;
	d = sqrt(dist.x * dist.x + dist.y * dist.y);
	d < 1 ? d = 1 : 0;
	d = (400 / d);
	color =  0x00000000;
	color_walls(data, ray, &color);
	while (h < d)
	{
//		if (1400 - slice + (((int)(data->win_h / 2) + (int)h) * data->win_w) <
//				1400 * 800)
//		{
			((int*)data->frame.img)[1400 - slice + (((int)(data->win_h / 2) \
				+ (int)h) * data->win_w)] = color;
			((int*)data->frame.img)[1400 - slice + (((int)(data->win_h / 2) \
				- (int)h2) * data->win_w)] = color;
//		}
		h += 1;
		h2 += 1;
	}
}
