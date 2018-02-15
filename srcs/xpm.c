/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 02:14:11 by acourtin          #+#    #+#             */
/*   Updated: 2018/02/15 07:43:53 by alerandy         ###   ########.fr       */
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

void				xpm_draw(t_data *data, t_xpm xpm)
{
	int i;

	i = -1;
	while (++i < xpm.width * xpm.height)
		((int*)(data->frame.img))[i] = xpm.img[i];
}

void				tmp_draw_f(t_data *data)
{
	int i;

	i = -1;
	while (++i < data->win_h * data->win_w)
		data->tmp.img[i] = data->fade.img[i];
}
