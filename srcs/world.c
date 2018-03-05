/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 17:18:38 by acourtin          #+#    #+#             */
/*   Updated: 2018/03/05 03:31:13 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		draw_wall(t_data *data, t_ray ray, int slice)
{
	static t_xpm	tex;
	static int		s = 0;
	double			h;
	double			h2;
	double			d;
	int				color;
	int				i;

	if (!s)
		tex = xpm_create(data, "./xpm/stone.xpm", 1400, 800);
	s = 1;
	d = ray.depth < 1 ? 1 : ray.depth;
	color = 0;
	if (ray.dir == NORTH || ray.dir == SOUTH)
		color = ray.dir == NORTH ? 0x0000FF : 0x00FF00;
	else
		color = ray.dir == EAST ? 0xFF0000 : 0xFF00FF;
	color -= ((int)(((1 + ray.depth) * 4)));
	color = color & 0x00FFFFFF;
	d = (800 / d);
	i = 1;
	h = (d + ((800 - d) / 2));
//	printf("%f\n", h);
	ray.x = ray.x - (int)ray.x;
//	printf("%f\n ", d);
	while (--h > (800 - d) / 2)
	{
		h2 = i * 256 - 800 * 128 + d * 128;
		if (ray.dir == NORTH)
			color = ((int*)tex.img)[(int)(ray.x + ((h2 * 1400) / d) / 256)];
		((int*)data->frame.img)[slice + (int)h * data->win_w] = color;
//	printf("%f\n ", h);
		i++;
	}
}
