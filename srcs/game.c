/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 21:40:30 by alerandy          #+#    #+#             */
/*   Updated: 2018/03/06 20:01:57 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		draw_skybox(t_data *data)
{
	static t_xpm	sky;
	static t_xpm	sky2;
	static int		s = 0;
	int				i;

	if (!s)
	{
		sky = xpm_create(data, "./xpm/skybox.xpm", 1400, 400);
		sky2 = xpm_create(data, "./xpm/skybox2.xpm", 1400, 400);
	}
	i = -1;
	while (++i < 1400 * 400)
	{
		if (data->map.t == DAY)
			((int*)(data->frame.img))[(i % 1400) + ((i / 1400) \
				* data->win_w)] = sky.img[abs((int)((i % 1400) \
				+ data->player.rot * 7.77) - ((i / 1400) * 2800))];
		else if (data->map.t == NIGHT)
			((int*)(data->frame.img))[(i % 1400) + ((i / 1400) \
				* data->win_w)] = sky2.img[abs((int)((i % 1400) \
				+ data->player.rot * 7.77) - ((i / 1400) * 2800))];
	}
	s = 1;
}

void			draw_map(t_data *data)
{
	int i;

	i = 0;
	data->loading ? debug(data->debug, "Dessin de la map.") : 0;
	if (data->map.t == 0)
		data->frame.img = ft_intset(data->frame.img, 0x00999999, data->win_w * \
			data->win_h);
	else
		data->frame.img = ft_intset(data->frame.img, 0x00333333, data->win_w * \
			data->win_h);
	data->loading ? debug(data->debug, "Reset to 0") : 0;
	draw_skybox(data);
	draw_minimap(data);
	data->loading ? debug(data->debug, "Dessin de la minimap.") : 0;
	loop_player(data);
	data->loading ? debug(data->debug, "Premier affichage vue.") : 0;
	loop_fps(data);
	data->loading ? debug(data->debug, "Initialisation de l'ATH.") : 0;
}
