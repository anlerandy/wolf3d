/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 21:04:20 by alerandy          #+#    #+#             */
/*   Updated: 2018/02/18 14:07:18 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static int		verify_file(t_data *data, char *filename)
{
	int fd;

	if ((fd = open(filename, O_RDONLY)) > 0)
	{
		close(fd);
	}
}

void			map(t_data *data, int map)
{
	int i;

	i = -1;
	debug(data->debug, "Chargement de la map : ");
	debug(data->debug, ft_itoa(map + 1));
	sleep(1);
	data->loading = 0;
	data->game_state = GAME;
	data->map.name = ft_strjoin("maps/map", ft_itoa(map + 1));
	while (++i <= 64 * 64)
	{
		data->map.tiles[i / 64][i % 64].type = FLOOR;
		data->map.tiles[i / 64][i % 64].collision = 0;
	}
	verify_file(data, data->map.name);
}
