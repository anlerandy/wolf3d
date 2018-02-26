/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun_anim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 16:22:20 by acourtin          #+#    #+#             */
/*   Updated: 2018/02/26 19:36:17 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		draw_gun(t_data *data, int framex, int framey)
{
	static double	movx = 0.0;
	static double	movy = 0.0;
	static t_xpm	gun;
	static int		s = 0;
	int				i;

	movx += data->player.k_val.walk * 0.3 + (data->player.k_val.run * 0.2) \
		* (data->player.end > 0.0);
	movy += data->player.k_val.walk * 0.2 + (data->player.k_val.run * 0.1) \
		* (data->player.end > 0.0);
	if (!s)
		gun = xpm_create(data, "./xpm/doublebarrel.xpm", 2500, 1500);
	s = 1;
	i = -1;
	while (++i < 500 * 500)
	{
		if (gun.img[(i % 500) + (framex * 500) + (((i / 500) + (framey * 500)) \
			* 2500)] != 0x0000FFFF && (i / 500) + 300 - sin(movy) * 10 \
			+ 10 < 800)
			((int*)(data->tmp.img))[(int)((i % 500) + cos(movx) * 10 + 600) \
				+ ((int)((i / 500) + 300 - sin(movy) * 10 + 10) \
				* data->win_w)] = gun.img[(i % 500) + (framex * 500) \
				+ (((i / 500) + (framey * 500)) * 2500)];
	}
}

void			draw_gun_mod(t_data *data, int frame)
{
	int framex;
	int framey;

	if (frame >= 2)
		frame++;
	if (frame >= 7)
		frame++;
	if (frame > 9)
		framey = 2;
	else if (frame > 4)
		framey = 1;
	else
		framey = 0;
	framex = frame % 5;
	draw_gun(data, framex, framey);
}
