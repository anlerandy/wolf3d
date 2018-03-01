/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tiles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 09:48:45 by acourtin          #+#    #+#             */
/*   Updated: 2018/02/28 16:12:53 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void			init_tiles(t_data *data, int *step)
{
	debug(data->debug, "Initialisation des tiles.");
	int i;

	i = 0;
	*step = 0;
	while (i < data->map.w * data->map.h)
	{
		data->map.tiles[i / data->map.w][i % data->map.w].z = 0;
		data->map.tiles[i / data->map.w][i % data->map.w].texture = WOOD;
		data->map.tiles[i / data->map.w][i % data->map.w].entity = NONE;
		i++;
	}
}
