/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 21:40:30 by alerandy          #+#    #+#             */
/*   Updated: 2018/03/12 08:56:35 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		draw_skybox(t_data *data)
{
	static t_xpm	sky;
	static t_xpm	sky2;
	static int		s = 0;
	int				i;

	if (!s)
	{
		sky = xpm_create(data, "xpm/skybox.xpm", 1400, 400);
		sky2 = xpm_create(data, "xpm/skybox2.xpm", 1400, 400);
	}
	i = -1;
	while (++i < 1400 * 400)
	{
		if (data->map.t == DAY)
			((int*)(data->frame.img))[(i % 1400) + ((i / 1400) \
				* data->win_w)] = sky.img[abs((int)((i % 1400) \
				+ data->player.rot * 7.77) - ((i / 1400) * 2800))];
		else if (data->map.t == NIGHT)
			((int*)(data->frame.img))[(i % 1400) + ((i / 1400) \
				* data->win_w)] = sky2.img[abs((int)((i % 1400) \
				+ data->player.rot * 7.77) - ((i / 1400) * 2800))];
	}
	s = 1;
}

static int		gradient(int c, int c2, double t)
{
	t_col		r1;
	t_col		r2;
	int			c3;

	r1.r = ((int)(c / 256) / 256);
	r1.g = ((int)(c / 256)) & 0x0000FF;
	r1.b = c & 0x0000FF;
	r2.r = ((int)(c2 / 256) / 256);
	r2.g = ((int)(c2 / 256)) & 0x0000FF;
	r2.b = c2 & 0x0000FF;
	r1.r = r1.r * t + r2.r * (1 - t);
	r1.g = r1.g * t + r2.g * (1 - t);
	r1.b = r1.b * t + r2.b * (1 - t);
	c3 = (r1.r * 256) * 256;
	c3 += r1.g * 256;
	c3 += r1.b;
	return (c3);
}

static void		draw_ground2(t_data *data)
{
	int		x;
	int		y;
	double	t;

	y = 400;
	x = 0;
	while (y < 800)
	{
		x = 0;
		t = (y - 399) / 400.;
		while (x++ < 1400)
			((int*)(data->frame.img))[x + y * 1400] = gradient(0x333333, 0, t);
		y++;
	}
}

static void		draw_ground(t_data *data)
{
	int		x;
	int		y;
	double	t;

	y = 400;
	x = 0;
	while (y < 800)
	{
		x = 0;
		t = (y - 399) / 400.;
		while (x++ < 1400)
			((int*)(data->frame.img))[x + y * 1400] = gradient(0x999999, \
			0x7e5e47, t);
		y++;
	}
}

void			draw_map(t_data *data)
{
	int i;

	i = 0;
	if (data->map.t == 0)
		draw_ground(data);
	else
		draw_ground2(data);
	data->loading ? debug(data->debug, "Dessin de la map.") : 0;
	data->loading ? debug(data->debug, "Reset to 0") : 0;
	draw_skybox(data);
	draw_minimap(data);
	data->loading ? debug(data->debug, "Dessin de la minimap.") : 0;
	loop_player(data);
	data->loading ? debug(data->debug, "Premier affichage vue.") : 0;
	data->debug ? loop_fps(data) : 0;
	data->loading ? debug(data->debug, "Initialisation de l'ATH.") : 0;
}
