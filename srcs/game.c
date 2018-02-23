/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 21:40:30 by alerandy          #+#    #+#             */
/*   Updated: 2018/02/23 19:24:52 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		draw_map(t_data *data)
{
	int i;

	i = 0;
	data->loading ? debug(data->debug, "Dessin de la map.") : 0;
	data->frame.img = ft_intset(data->frame.img, 0x00CCCCCC, data->win_w * \
		data->win_h);
	data->frame.img = ft_intset(data->frame.img, 0x00239FFE, data->win_w * \
		(data->win_h / 2));
	draw_minimap(data);
	loop_player(data);
}
