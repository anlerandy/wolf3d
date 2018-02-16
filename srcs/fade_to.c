/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fade_to.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 04:04:24 by alerandy          #+#    #+#             */
/*   Updated: 2018/02/16 07:25:31 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void	intro(t_data *data)
{
	t_xpm intr;

//	data->intro.launched == 1 ? data->flag = 0 : data->flag;
	data->intro.qd && !data->intro.auth ? sleep(2) : sleep(0);
	if (!data->intro.qd)
	{
		debug(data->debug, "Lancement de l'intro.");
		intr = xpm_create(data, "./xpm/aea.xpm", 1400, 800);
		data->intro.qd = 1;
		init_menu(data);
	}
	else if (!data->intro.auth)
	{
		intr = xpm_create(data, "./xpm/menu.xpm", 1400, 800);
		data->intro.auth = 1;
	}
	else if (!data->intro.fin)
	{
		data->intro.launched = 2;
		data->intro.fin = 1;
	}
	if (data->intro.launched == 1 && !data->intro.fin)
		xpm_draw(data, intr, 0, 0);
}

static void	fade_to2(t_data *data)
{
	int i;

	data->fade_c = !data->flag ? 0x00000000 : data->fade_c;
	if (data->flag < 255 / FADE)
	{
		data->fade_c += 0x01000000 * FADE;
		i = -1;
		while (++i < data->win_w * data->win_h)
			data->fade.img[i] = data->frame.img[i];
		data->fade.img = ft_intadd(data->fade.img, data->fade_c,
				data->win_w * data->win_h);
		data->flag++;
	}
	if (data->flag >= 255 / FADE)
		data->intro.launched = 1;
	data->intro.launched == 1 && !data->intro.fin ? intro(data) : i;
}

int			fade_to(void *param)
{
	t_data	*data;

	data = (t_data*)param;
	if (data->game_state == MENU)
	{
		fade_to2(data);
		mlx_put_image_to_window(data->mlx, data->win, data->frame.pimg, 0, 0);
		if (data->flag < 255 / FADE)
			mlx_put_image_to_window(data->mlx, \
				data->win, data->fade.pimg, 0, 0);
		if (data->intro.fin == 1)
			draw_menu(data);
	}
	else if (data->game_state == GAME)
	{
		ft_intset(data->frame.img, 0x00000000, data->win_w * data->win_h);
		mlx_put_image_to_window(data->mlx, data->win, data->frame.pimg, 0, 0);
	}
	return (0);
}
