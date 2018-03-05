/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 17:18:38 by acourtin          #+#    #+#             */
/*   Updated: 2018/03/04 22:36:58 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void	load_texture(t_data *data, t_xpm texture[4])
{
	texture[BRICK] = xpm_create(data, "./xpm/brick.xpm", 1400, 800);
	texture[WOOD] = xpm_create(data, "./xpm/wood.xpm", 1400, 800);
	texture[STONE] = xpm_create(data, "./xpm/stone.xpm", 1400, 800);
	texture[METAL] = xpm_create(data, "./xpm/metal.xpm", 1400, 800);
}

static void	determine_colors(t_ray r, int *color)
{
	if (r.dir == NORTH || r.dir == SOUTH)
		*color = r.dir == NORTH ? 0x0000FF : 0x00FF00;
	else
		*color = r.dir == EAST ? 0xFF0000 : 0xFF00FF;
	*color -= ((int)(((1 + r.depth) * 4)));
	*color += 0x0000000 & 0xFF000000;
}

void		draw_wall(t_data *data, t_ray r, int slice)
{
	double			h;
	double			d;
	int				color;
	static int		s = 0;
	static t_xpm	texture[5];

	if (!s)
		load_texture(data, texture);
	s = 1;
  d = ray.depth < 1 ? 1 : ray.depth;
	if (ray.dir == NORTH || ray.dir == SOUTH)
		color = ray.dir == NORTH ? 0x0000FF : 0x00FF00;
	else
		color = ray.dir == EAST ? 0xFF0000 : 0xFF00FF;
	color -= ((int)(((1 + ray.depth) * 4)));
	color = color & 0x00FFFFFF;
	d = (800 / d);
	i = 1;
	h = (d + ((800 - d) / 2));
	ray.x = ray.x - (int)ray.x;
	while (++h < d)
	{
		if (r.tx == WOOD || r.tx == STONE || r.tx == METAL || r.tx == BRICK)
			color = texture[r.tx].img[(int)(slice + (h * 1400))];
		((int*)data->frame.img)[slice + (int)h * data->win_w] = color;
		i++;
  }
}
