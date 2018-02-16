/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 02:14:11 by acourtin          #+#    #+#             */
/*   Updated: 2018/02/16 07:24:05 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_xpm				xpm_create(t_data *data, char *xpmname, int w, int h)
{
	t_xpm xpm;

	xpm.width = w;
	xpm.height = h;
	xpm.pimg = mlx_xpm_file_to_image(data->mlx, xpmname, &w, &h);
	xpm.img = (int*)mlx_get_data_addr(xpm.pimg, &xpm.bpp, &xpm.s_l, &xpm.ndia);
	debug(data->debug, "Creation texture : ");
	debug(data->debug, xpmname + 6);
	return (xpm);
}

void				xpm_draw(t_data *data, t_xpm xpm, int x, int y)
{
	int i;
	int j;

	j = 0;
	while (j < xpm.height && j < data->win_h)
	{
		i = 0;
		while (i < xpm.width && i < data->win_w)
		{
			if ((i + x) + (((j + y) * data->win_w) < \
					data->win_w * data->win_h) && i < xpm.width - x)
				((int*)(data->frame.img))[(i + x) + ((j + y) \
					* data->win_w)] = xpm.img[i + (j * data->win_w)];
			i++;
		}
		j++;
	}
}

void				tmp_draw_f(t_data *data)
{
	int i;

	i = -1;
	while (++i < data->win_h * data->win_w)
		data->tmp.img[i] = data->fade.img[i];
}
