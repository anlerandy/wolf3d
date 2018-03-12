/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loading.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 16:20:48 by alerandy          #+#    #+#             */
/*   Updated: 2018/03/12 08:56:24 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		set_load(t_data *data, t_frame *right, t_frame *left)
{
	static t_xpm	load;
	static int		x = 0;

	right->height = 800;
	right->width = 700;
	left->width = 700;
	left->height = 800;
	right->pimg = mlx_new_image(data->mlx, right->width, right->height);
	right->img = mlx_get_data_addr(right->pimg, &(right->bpp), &(right->s_l),
			&(right->ndia));
	left->pimg = mlx_new_image(data->mlx, left->width, left->height);
	left->img = mlx_get_data_addr(left->pimg, &(left->bpp), &(left->s_l),
			&(left->ndia));
	if (!x)
		load = xpm_create(data, "xpm/door.xpm", 1400, 800);
	x = 1;
	xpm_draw_img(right, load, 700, 0);
	xpm_draw_img(left, load, 0, 0);
}

static void	put_all(t_data *data, int i, t_frame right, t_frame left)
{
	mlx_put_image_to_window(data->mlx, data->win, data->frame.pimg, 0, 0);
	if (data->loading != 3 && data->game_state == GAME)
		mlx_put_image_to_window(data->mlx, data->win, data->minimap.pimg, \
				10, 10);
	mlx_put_image_to_window(data->mlx, data->win, data->tmp.pimg, 0, 0);
	mlx_put_image_to_window(data->mlx, data->win, right.pimg, 1400 - i, 0);
	mlx_put_image_to_window(data->mlx, data->win, left.pimg, -700 + i, 0);
}

void		loading(t_data *data)
{
	t_frame	right;
	t_frame	left;
	int		i;

	set_load(data, &right, &left);
	if (data->loading && data->load_ani < 700)
	{
		data->load_ani += DOORSPEED;
		i = data->load_ani > 700 ? 700 : data->load_ani;
		mlx_put_image_to_window(data->mlx, data->win, right.pimg, 1400 - i, 0);
		mlx_put_image_to_window(data->mlx, data->win, left.pimg, -700 + i, 0);
		if (data->load_ani >= 700)
			data->loading = 2;
	}
	else if (!data->loading && data->load_ani > 0)
	{
		data->load_ani -= DOORSPEED;
		i = data->load_ani < 0 ? 0 : data->load_ani;
		put_all(data, i, right, left);
	}
	mlx_destroy_image(data->mlx, left.pimg);
	mlx_destroy_image(data->mlx, right.pimg);
}

void		loading2(t_data *data)
{
	t_frame	right;
	t_frame	left;
	int		i;

	set_load(data, &right, &left);
	if (data->loading && data->load_ani < 700 && data->game_state == PAUSE)
	{
		data->load_ani += DOORSPEED;
		i = data->load_ani > 700 ? 700 : data->load_ani;
		mlx_put_image_to_window(data->mlx, data->win, right.pimg, 1400 - i, 0);
		mlx_put_image_to_window(data->mlx, data->win, left.pimg, -700 + i, 0);
		if (data->load_ani >= 700)
			rebuild_menu(data);
	}
	else if (data->loading == 3 && data->load_ani > 0)
	{
		data->load_ani -= DOORSPEED;
		i = data->load_ani < 0 ? 0 : data->load_ani;
		put_all(data, i, right, left);
		i == 0 ? data->loading = 0 : i;
	}
	mlx_destroy_image(data->mlx, left.pimg);
	mlx_destroy_image(data->mlx, right.pimg);
}
