/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun_anim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 16:22:20 by acourtin          #+#    #+#             */
/*   Updated: 2018/03/12 09:07:22 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		draw_gun(t_data *data, int framex, int framey, int i)
{
	static double	movx = 0.0;
	static double	movy = 0.0;
	static t_xpm	gun;
	static int		s = 0;

	movx += ((data->player.k_val.walk * 0.3 + 0.2 \
		* (data->player.k_val.run == 1 && data->player.end > 0 \
		&& data->player.k_val.walk == 1)) * (data->player.is_moving == 1));
	movy += ((data->player.k_val.walk * 0.2 + 0.1 \
		* (data->player.k_val.run == 1 && data->player.end > 0 \
		&& data->player.k_val.walk == 1)) * (data->player.is_moving == 1));
	if (!s)
		gun = xpm_create(data, "xpm/doublebarrel.xpm", 2500, 1500);
	s = 1;
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
	draw_gun(data, framex, framey, -1);
}
