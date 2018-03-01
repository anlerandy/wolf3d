/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tiles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 09:48:45 by acourtin          #+#    #+#             */
/*   Updated: 2018/03/01 07:39:19 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void			init_tiles(t_data *data, int *step)
{
	int			i;

	i = 0;
	debug(data->debug, "Initialisation des tiles.");
	*step = 0;
	while (i < data->map.w * data->map.h)
	{
		data->map.tiles[i / data->map.w][i % data->map.w].z = 0;
		data->map.tiles[i / data->map.w][i % data->map.w].texture = WOOD;
		data->map.tiles[i / data->map.w][i % data->map.w].entity = NONE;
		i++;
	}
}
