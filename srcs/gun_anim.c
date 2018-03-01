/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun_anim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 16:22:20 by acourtin          #+#    #+#             */
/*   Updated: 2018/02/27 17:49:56 by acourtin         ###   ########.fr       */
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
	static int	takeammo = 0;
	int			framex;
	int			framey;

	if (frame >= 7)
		frame++;
	if (frame > 9)
		framey = 2;
	else if (frame > 4)
		framey = 1;
	else
		framey = 0;
	if ((frame == 9 || frame == 12) && takeammo == 0)
	{
		data->player.amo--;
		takeammo = 1;
	}
	else if (frame != 9 && frame != 12 && takeammo == 1)
		takeammo = 0;
	framex = frame % 5;
	draw_gun(data, framex, framey);
}
