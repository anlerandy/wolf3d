/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 17:18:38 by acourtin          #+#    #+#             */
/*   Updated: 2018/03/01 06:00:10 by alerandy         ###   ########.fr       */
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
	d = ray.depth;
	color = 0;
	if (ray.dir == NORTH || ray.dir == SOUTH)
		color = ray.dir == NORTH ? 0x000FF : 0x00FF00;
	else
		color = ray.dir == EAST ? 0xFF0000 : 0xFF00FF;
	color -=  ((int)(((1 + ray.depth) * 4)));
	color +=  0x0000000 & 0xFF000000;
	d < 1 ? d = 1 : 0;
	d = (400 / d);
	while (h < d)
	{
		if (slice + (((data->win_h / 2) + h) * data->win_w) < 1400 * 800)
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
