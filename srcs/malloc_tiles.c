/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_tiles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 02:03:58 by acourtin          #+#    #+#             */
/*   Updated: 2018/03/07 02:10:38 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void			malloc_tiles(t_data *data, int h, int w)
{
	int i;

	i = -1;
	data->map.tiles = NULL;
	if (!(data->map.tiles = ft_memalloc(sizeof(t_tile*) * h)))
		usage(13);
	while (++i < h)
	{
		data->map.tiles[i] = NULL;
		if (!(data->map.tiles[i] = ft_memalloc(sizeof(t_tile) * w)))
			usage(13);
	}
}
