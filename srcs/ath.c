/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ath.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 02:34:01 by alerandy          #+#    #+#             */
/*   Updated: 2018/02/27 18:54:59 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		draw_pv(t_data *data)
{
	static int	ani_pv = 100;
	int			x;
	int			y;
	int			pv_scale;
	int			c;

	data->player.hp <= 100 ? c = 0x28f57f37 : 0;
	data->player.hp <= 75 ? c = 0x28f2673a : 0;
	data->player.hp <= 50 ? c = 0x28ff3333 : 0;
	data->player.hp <= 25 ? c = 0x28ff0000 : 0;
	data->player.hp == 100 ? c = 0x28ff9933 : 0;
	ani_pv > data->player.hp ? ani_pv-- : 0;
	ani_pv < data->player.hp ? ani_pv++ : 0;
	pv_scale = floor(ani_pv * 294 / 100);
	y = -1;
	while (++y < 25)
	{
		x = -1 + floor(y * 0.4);
		while (++x < pv_scale - floor(y * 1.6))
			((int*)(data->tmp.img))[(111 + x) + ((695 + y) * data->win_w)] = c;
	}
}

void		draw_end(t_data *data)
{
	int			x;
	int			y;
	int			end_scale;
	int			c;

	data->player.end <= 100 ? c = 0x2ff57f37 : 0;
	data->player.end <= 75 ? c = 0x2ff2673a : 0;
	data->player.end <= 50 ? c = 0x2fff3333 : 0;
	data->player.end <= 25 ? c = 0x2fff0000 : 0;
	data->player.end == 100 ? c = 0x2fff9933 : 0;
	end_scale = floor(data->player.end * 167 / 100);
	y = -1;
	while (++y < 25)
	{
		x = -1 + floor(y * 0.4);
		while (++x < end_scale - floor(y * 1.6))
			((int*)(data->tmp.img))[(123 + x) + ((725 + y) * data->win_w)] = c;
	}
}

void		ath_xpm(t_data *data)
{
	static t_xpm	ath;
	static int		s;
	int				i;

	if (!s)
		ath = xpm_create(data, "./xpm/ath.xpm", 1225, 75);
	s = 1;
	i = -1;
	while (++i < 1225 * 75)
		((int*)(data->tmp.img))[(i % 1225) + 43 + (((i / 1225) + 685) \
			* data->win_w)] = ath.img[(i % 1225) + ((i / 1225) * 1225)];
}

static void	draw_reload(t_data *data)
{
	static t_xpm	rld;
	static int		s = 0;
	int i;

	if (!s)
		rld = xpm_create(data, "./xpm/reload.xpm", 120, 25);
	s = 1;
	i = -1;
	while (++i < 120 * 25)
	{
		if (rld.img[(i % 120) + ((i / 120) * 120)] != 0x00FEFFFF)
			((int*)(data->tmp.img))[(i % 120) + 1200 + (((i / 120) + 665) \
			* data->win_w)] = rld.img[(i % 120) + ((i / 120) * 120)];
	}
}

void		draw_ath(t_data *data)
{
	char *amo;
	char *fps;

	data->tmp.img = ft_intset(data->tmp.img, 0xff000000,
			data->win_h * data->win_w);
	ath_xpm(data);
	draw_gun_mod(data, data->player.gun_frame);
	draw_pv(data);
	draw_end(data);
	if (data->player.amo_chamber == 0 && data->actual_time % 2 == 0)
		draw_reload(data);
	amo = ft_itoa(data->player.amo / 10);
	ft_type(data, amo, 1260, 713);
	ft_strdel(&amo);
	amo = ft_itoa(data->player.amo % 10);
	ft_type(data, amo, 1285, 713);
	if (data->debug)
	{
		ft_type(data, "FPS", 1000, 10);
		fps = ft_itoa(data->fps);
		ft_type(data, fps, 1150, 10);
		ft_strdel(&fps);
	}
	ft_strdel(&amo);
}
