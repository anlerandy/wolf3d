/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 17:18:38 by acourtin          #+#    #+#             */
/*   Updated: 2018/02/23 20:55:24 by alerandy         ###   ########.fr       */
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
	dist.x > 0 && dist.y > 0 ? color = 0x00000001 : 0;
	dist.y > 0 && dist.y < 0 ? color = 0x00000100 : 0;
	dist.y < 0 && dist.y < 0 ? color = 0x00010000 : 0;
	dist.x < 0 && dist.y > 0 ? color = 0x00010100 : 0;
	color *= ((100 - ray.depth) * 4) / 2;
	d = sqrt(dist.x * dist.x + dist.y * dist.y);
	d = (100 - d) * 2;
	while (h < d)
	{
		((int*)data->frame.img)[1400 - slice + (((int)(data->win_h / 2) \
				+ (int)h) * data->win_w)] = color;
		((int*)data->frame.img)[1400 - slice + (((int)(data->win_h / 2) \
				- (int)h2) * data->win_w)] = color;
		h += 0.5;
		h2 += 0.5;
	}
}
