/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 02:14:11 by acourtin          #+#    #+#             */
/*   Updated: 2018/03/05 10:07:16 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_xpm				xpm_create(t_data *data, char *xpmname, int w, int h)
{
	t_xpm xpm;

	debug(data->debug, "Creation de la texture : ");
	debug(data->debug, xpmname + 6);
	xpm.pimg = NULL;
	xpm.img = NULL;
	xpm.width = w;
	xpm.height = h;
	if (!(xpm.pimg = mlx_xpm_file_to_image(data->mlx, xpmname, &w, &h)))
		usage(3);
	xpm.img = (int*)mlx_get_data_addr(xpm.pimg, &xpm.bpp, &xpm.s_l, &xpm.ndia);
	if (!xpm.img)
		usage(3);
	debug(data->debug, "Réussi.");
	return (xpm);
}

void				xpm_draw_to_tmp(t_data *data, t_xpm xpm)
{
	int i;
	int j;

	j = 0;
	while (j < xpm.height && j < data->win_h)
	{
		i = 0;
		while (i < xpm.width && i < data->win_w)
		{
			if (i + ((j * data->win_w) < \
					data->win_w * data->win_h) && i < xpm.width)
				((int*)(data->tmp.img))[i + (j \
					* data->win_w)] = xpm.img[i + (j * data->win_w)];
			i++;
		}
		j++;
	}
}

void				xpm_draw(t_data *data, t_xpm xpm)
{
	int i;
	int j;

	j = 0;
	while (j < xpm.height && j < data->win_h)
	{
		i = 0;
		while (i < xpm.width && i < data->win_w)
		{
			if (i + ((j * data->win_w) < \
					data->win_w * data->win_h) && i < xpm.width)
				((int*)(data->frame.img))[i + (j \
					* data->win_w)] = xpm.img[i + (j * data->win_w)];
			i++;
		}
		j++;
	}
}

void				xpm_draw_img(t_frame *tmp, t_xpm xpm, int x, int y)
{
	int i;
	int j;

	j = 0;
	while (j < tmp->height)
	{
		i = 0;
		while (i < tmp->width)
		{
			if (i < xpm.width && j < xpm.height)
				((int*)(tmp->img))[i + (tmp->width * j)] =
						xpm.img[x + i + y + (j * xpm.width)];
			i++;
		}
		j++;
	}
}
