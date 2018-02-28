/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 21:40:30 by alerandy          #+#    #+#             */
/*   Updated: 2018/02/28 16:40:28 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		draw_skybox(t_data *data)
{
	static t_xpm	*sky;
	static int		s = 0;
	int				i;

	if (!s)
	{
		data->player.rot = 90;
		sky = (t_xpm*)ft_memalloc(sizeof(t_xpm));
		*sky = xpm_create(data, "./xpm/skybox.xpm", 1400, 400);
	}
	i = -1;
	while (++i < 1400 * 400)
		((int*)(data->frame.img))[(i % 1400) + ((i / 1400) \
			* data->win_w)] = sky->img[abs((int)((i % 1400) - data->player.rot \
			* 7.77) + ((i / 1400) * 2800))];
	if (!s)
		debug(data->debug, "Premier dessin effectué.");
	s = 1;
}

void			draw_map(t_data *data)
{
	int i;

	i = 0;
	data->loading ? debug(data->debug, "Dessin de la map.") : 0;
	data->frame.img = ft_intset(data->frame.img, 0x00999999, data->win_w * \
		data->win_h);
	draw_skybox(data);
	draw_minimap(data);
	loop_player(data);
	loop_fps(data);
}
