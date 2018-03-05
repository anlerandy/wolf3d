/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 17:18:38 by acourtin          #+#    #+#             */
/*   Updated: 2018/03/05 16:23:06 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void	load_texture(t_data *data, t_xpm texture[4])
{
	texture[BRICK] = xpm_create(data, "./xpm/brick2.xpm", 1400, 800);
	texture[WOOD] = xpm_create(data, "./xpm/wood2.xpm", 1400, 800);
	texture[STONE] = xpm_create(data, "./xpm/stone2.xpm", 1400, 800);
	texture[METAL] = xpm_create(data, "./xpm/metal2.xpm", 1400, 800);
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

static int	shading(t_ray r, int color)
{
	int c;
	int	i;

	i = r.depth < 3 ? 3 : r.depth;
	c = (((int)((color & 0xFF0000) * 3 / i)) & 0xFF0000);
	c += (((int)((color & 0x00FF00) * 3 / i)) & 0x00FF00);
	c += (((int)((color & 0x0000FF) * 3 / i)) & 0x0000FF);
	return (c);
}

void		draw_wall(t_data *data, t_ray r, int slice)
{
	t_wall			util;
	static int		s = 0;
	static t_xpm	texture[4];

	!s ? load_texture(data, texture) : 0;
	s = 1;
	util.mxheight = r.depth;
	determine_colors(r, &(util.color));
	util.mxheight = (800 / util.mxheight);
	util.wheight = (int)(util.mxheight + ((800 - util.mxheight) / 2));
	r.x = r.dir == NORTH || r.dir == SOUTH ? r.x - (int)r.x : r.y - (int)r.y;
	while (--util.wheight > ((800 - util.mxheight) / 2))
	{
		util.currpix = ((((800 - util.wheight) * 256 - 800 * 128 + \
						util.mxheight * 128) * 800) / util.mxheight) / 256;
		util.texpix = (int)(r.x * 1400 + (util.currpix * 1400));
		util.walpix = (int)slice + (800 - (int)util.wheight) * data->win_w;
		if (r.tx == WOOD || r.tx == STONE || r.tx == METAL || r.tx == BRICK)
			util.color = texture[r.tx].img[util.texpix];
		if (r.tx == MULTI)
			util.color = texture[r.dir % 4].img[util.texpix];
		if (util.walpix < 1400 * 800 && util.walpix >= 0)
			((int*)data->frame.img)[util.walpix] = shading(r, util.color);
	}
}
