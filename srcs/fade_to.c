/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fade_to.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 04:04:24 by alerandy          #+#    #+#             */
/*   Updated: 2018/02/23 18:27:19 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void	intro(t_data *data)
{
	t_xpm intr;

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
		xpm_draw(data, intr);
}

static void	input_loop(t_data *data)
{
	if (data->game_state == GAME)
	{
		data->player.k_val.rot == 1 ? data->player.rot += PLAYER_ROT : 0;
		data->player.k_val.rot == -1 ? data->player.rot -= PLAYER_ROT : 0;
		data->player.k_val.walk == 1 ? move_player(data, 1) : 0;
		data->player.k_val.walk == -1 ? move_player(data, -1) : 0;
		if (data->player.k_val.run && data->player.end > 0)
		{
			data->player.k_val.walk == 1 ? move_player(data, 2) : 0;
			data->player.k_val.walk == 1 ? data->player.end -= 2 : 0;
			data->player.end == 0 ? data->player.end = -100 : 0;
		}
		else if (data->player.end < 100)
			data->player.end++;
	}
}

static void	ingame(t_data *data)
{
	if (data->game_state == GAME)
	{
		input_loop(data);
		draw_map(data);
		draw_ath(data);
		mlx_put_image_to_window(data->mlx, data->win, data->frame.pimg, 0, 0);
		mlx_put_image_to_window(data->mlx, data->win, data->tmp.pimg, 0, 0);
		mlx_put_image_to_window(data->mlx, data->win, data->minimap.pimg, \
				10, 10);
	}
	if (data->game_state == PAUSE)
	{
		data->frame.img = ft_intset(data->frame.img, 0x00000000, data->win_w *
				data->win_h);
		draw_pause(data);
		mlx_put_image_to_window(data->mlx, data->win, data->frame.pimg, 0, 0);
		mlx_put_image_to_window(data->mlx, data->win, data->tmp.pimg, 0, 0);
	}
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
	if (data->loading == 2)
		map(data, data->menu.selection);
	if (data->game_state == MENU && (!data->loading || data->loading == 3))
	{
		data->intro.fin ? 0 : fade_to2(data);
		mlx_put_image_to_window(data->mlx, data->win, data->frame.pimg, 0, 0);
		if (data->flag < 255 / FADE && !data->intro.fin)
			mlx_put_image_to_window(data->mlx, data->win, data->fade.pimg,
					0, 0);
		if (data->intro.fin == 1)
			draw_menu(data);
		mlx_put_image_to_window(data->mlx, data->win, data->tmp.pimg, 0, 0);
	}
	if (data->game_state == GAME || data->game_state == PAUSE)
		ingame(data);
	if (data->loading == 3)
		loading2(data);
	else if (data->loading == 1 || data->load_ani > 0)
		loading(data);
	return (0);
}
