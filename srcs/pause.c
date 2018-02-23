/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pause.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 15:05:12 by acourtin          #+#    #+#             */
/*   Updated: 2018/02/23 19:24:25 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		draw_select(t_data *data, int x)
{
	int		i;
	int		y;

	y = 0;
	data->tmp.img = ft_intset(data->tmp.img, 0xff000000, data->win_w *
			data->win_h);
	while (y < 50)
	{
		i = 0;
		while (i < 462)
		{
			((int*)(data->tmp.img))[(i + 468) + ((y + 345) * data->win_w) +
				(x * 55) * data->win_w] = 0xD04c0000;
			i++;
		}
		y++;
	}
}

void			draw_pause(t_data *data)
{
	static t_xpm	pause;
	static int		x = 0;

	data->player.k_val.walk = 0;
	data->player.k_val.rot = 0;
	data->player.k_val.run = 0;
	data->player.k_val.fire = 0;
	if (!x)
		pause = xpm_create(data, "./xpm/pause.xpm", 1400, 800);
	x = 1;
	xpm_draw(data, pause);
	draw_select(data, data->menu.selection);
}

void			execute_pause(t_data *data)
{
	data->menu.selection == 0 ? data->game_state = GAME : 0;
	data->menu.selection == 2 ? data->loading = 3 : 0;
	data->menu.selection == 3 ? usage(42) : 0;
}
