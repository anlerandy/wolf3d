/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 21:04:20 by alerandy          #+#    #+#             */
/*   Updated: 2018/02/18 16:47:19 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		get_size(t_data *data, char *line, int *w, int *h)
{
	*h += 1;
	if (*w < ft_strlen(line))
		*w = ft_strlen(line);
}

static int		verify_file(t_data *data, char *filename, int *w, int *h)
{
	int		fd;
	char	*line;
	int		step;

	if ((fd = open(filename, O_RDONLY)) > 0)
	{
		step = 0;
		while (get_next_line(fd, &line) == 1)
		{
			if (ft_strcmp(line, "TEXTURE:") == 0)
				step = 1;
			else if (ft_strcmp(line, "HEIGHT:") == 0)
				break ;
			else if (step == 1)
				get_size(data, line, w, h);
			ft_strdel(&line);
		}
		ft_strdel(&line);
		close(fd);
	}
	else
		return (0);
	return (1);
}

void			map(t_data *data, int map)
{
	int i;
	int h;
	int w;

	i = -1;
	h = 0;
	w = 0;
	debug(data->debug, "Chargement de la map : ");
	debug(data->debug, ft_itoa(map + 1));
	sleep(1);
	data->loading = 0;
	data->game_state = GAME;
	data->map.name = ft_strjoin("maps/map", ft_itoa(map + 1));
	if (verify_file(data, data->map.name, &w, &h) == 0)
		usage(4);
	data->map.width = w;
	data->map.height = h;
	data->map.tiles = ft_memalloc(sizeof(int*) * h);
	while (++i < h)
		data->map.tiles[i] = ft_memalloc(sizeof(int) * w);
}
