/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 14:59:21 by alerandy          #+#    #+#             */
/*   Updated: 2018/02/15 07:40:55 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	mlx_launcher(t_data *data)
{
	t_xpm menu;

	menu = xpm_create(data, "./xpm/menu.xpm", 1400, 800);
	xpm_draw(data, menu);
	debug(data->debug, "Lancement MLX.");
	mlx_loop_hook(data->mlx, fade_to, (void*)data);
	mlx_hook(data->win, 2, 0, press, (void*)data);
	mlx_hook(data->win, 3, 0, release, (void*)data);
	mlx_loop(data->mlx);
}

void	set_data(t_data *data)
{
	data->win_w = 1400;
	data->win_h = 800;
	data->debug = 1;
	data->flag = 0;
	data->intro.launched = 0;
}

void	set_img(t_data *data)
{
	if (!data->win_h || !data->win_w)
		usage(2);
	if (!(data->win = mlx_new_window(data->mlx, data->win_w, data->win_h, WIN)))
		usage(2);
	data->frame.pimg = mlx_new_image(data->mlx, data->win_w, data->win_h);
	data->frame.img = mlx_get_data_addr(data->frame.pimg, &(data->frame.bpp),
			&(data->frame.s_l), &(data->frame.ndia));
	data->frame.img = ft_intset(data->frame.img, 0, data->win_w * data->win_h);
	data->fade.pimg = mlx_new_image(data->mlx, data->win_w, data->win_h);
	data->fade.img = mlx_get_data_addr(data->fade.pimg, &(data->fade.bpp),
			&(data->fade.s_l), &(data->fade.ndia));
	data->fade.img = ft_intset(data->fade.img, 0, data->win_w * data->win_h);
	data->tmp.pimg = mlx_new_image(data->mlx, data->win_w, data->win_h);
	data->tmp.img = mlx_get_data_addr(data->tmp.pimg, &(data->tmp.bpp),
			&(data->tmp.s_l), &(data->tmp.ndia));
	data->tmp.img = ft_intset(data->tmp.img, 0, data->win_w * data->win_h);
	if (!data->frame.img || !data->frame.pimg)
		usage(2);
}

int		main(void)
{
	t_data		*data;
	int			i;

	i = 0;
	data = NULL;
	if (!(data = ft_memalloc(sizeof(t_data))))
		usage(1);
	set_data(data);
	debug(data->debug, "Environnement chargé.\nInitialisation de MLX.");
	if (!(data->mlx = mlx_init()))
		usage(2);
	set_img(data);
	debug(data->debug, "MLX READY");
	mlx_launcher(data);
	exit(0);
}
