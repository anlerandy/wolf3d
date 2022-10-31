/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pause.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 15:05:12 by acourtin          #+#    #+#             */
/*   Updated: 2022/10/31 15:54:11 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		draw_select(t_data *data, int x)
{
	int		i;
	int		y;

	y = 0;
	while (y < 50)
	{
		i = 0;
		while (i < 462)
		{
			((int*)(data->frame.img))[(i + 468) + ((y + 345) * data->win_w) +
				(x * 55) * data->win_w] += 0x002F0005 & 0x00FF00FF;
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
	draw_map(data);
	xpm_draw_to_tmp(data, pause);
	draw_select(data, data->menu.selection);
	mlx_put_image_to_window(data->mlx, data->win, data->frame.pimg, 0, 0);
}

void			draw_input(t_data *data)
{
	int			x;
	int			y;
	int			space;

	x = 200;
	y = 50;
	space = 70;
	draw_map(data);
	// data->tmp.img = ft_intset(data->tmp.img, 0x70550000,
	// 		data->win_h * data->win_w);
	ft_type(data, "Marcher      W ou S", x + 25, y);
	ft_type(data, "Tourner      A ou D", x + 25, y + space);
	ft_type(data, "Courir       shift", x + 25, y + space * 2);
	ft_type(data, "Tirer        espace", x + 25, y + space * 3);
	ft_type(data, "Recharger    R", x + 25, y + space * 4);
	ft_type(data, "DEBUG*       ~", x + 25, y + space * 5);
	ft_type(data, "DEBUG Vie    PAD", x + 25, y + space * 6);
	ft_type(data, "Retour       P", x + 25, y + space * 8);
	ft_type(data, "Quitter le jeu > echap", x + 25, y + space * 9);
	mlx_put_image_to_window(data->mlx, data->win, data->frame.pimg, 0, 0);
	// mlx_put_image_to_window(data->mlx, data->win, data->tmp.pimg, 0, 0);
}

void			execute_pause(t_data *data)
{
	data->menu.selection == 0 ? data->game_state = GAME : 0;
	data->menu.selection == 1 ? data->game_state = INPUT : 0;
	data->menu.selection == 2 ? data->loading = 3 : 0;
	data->menu.selection == 3 ? usage(42) : 0;
}
