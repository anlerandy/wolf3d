/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 17:18:38 by acourtin          #+#    #+#             */
/*   Updated: 2018/02/24 20:19:45 by alerandy         ###   ########.fr       */
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
	dist.x = data->player.pos.x - ray.x;
	dist.y = data->player.pos.y - ray.y;
	color =  0x000001 + ((int)(((100 - ray.depth) * 4) / 2));
	d = sqrt(dist.x * dist.x + dist.y * dist.y);
	d < 1 ? d = 1 : 0;
	d = (398 / d);
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
