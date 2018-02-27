/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 17:18:38 by acourtin          #+#    #+#             */
/*   Updated: 2018/02/27 19:13:04 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		draw_wall(t_data *data, t_ray ray, int slice)
{
	double	h;
	double	d;
	double	h2;
	t_ray	dist;
	int		color;

	h = 0;
	h2 = 1;
//	dist.x = data->player.pos.x - ray.x;
//	dist.y = data->player.pos.y - ray.y;
//	d = sqrt(dist.x * dist.x + dist.y * dist.y);
	d = ray.depth;
	color =  0x000001 + ((int)(((100 - ray.depth) * 4) / 2));
	d < 1 ? d = 1 : 0;
	d = (400 / d);
	while (h < d)
	{
		if (slice + (((int)(data->win_h / 2) + (int)h) * data->win_w) <
				1400 * 800)
		{
			((int*)data->frame.img)[slice + (((int)(data->win_h / 2) \
				+ (int)h) * data->win_w)] = color;
			((int*)data->frame.img)[slice + (((int)(data->win_h / 2) \
				- (int)h2) * data->win_w)] = color;
		}
		h += 1;
		h2 += 1;
	}
}
