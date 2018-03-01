/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 19:08:02 by alerandy          #+#    #+#             */
/*   Updated: 2018/03/01 07:52:32 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		map_clear(t_data *data)
{
	int		i;

	i = 0;
	debug(data->debug, "Supression de la map : ");
	debug(data->debug, data->map.name);
	ft_strdel(&(data->map.name));
	while (i < data->map.h)
	{
		ft_memdel((void**)&(data->map.tiles[i]));
		i++;
	}
	ft_memdel((void**)&(data->map.tiles));
	data->map.w = 0;
	data->map.h = 0;
}
