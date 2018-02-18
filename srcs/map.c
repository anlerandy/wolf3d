/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 21:04:20 by alerandy          #+#    #+#             */
/*   Updated: 2018/02/18 18:44:43 by acourtin         ###   ########.fr       */
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

static int		detect_step(char *line, int *i, int *step)
{
	if (ft_strcmp(line, "TEXTURE:") == 0)
	{
		*step = 1;
		*i = 0;
		return (1);
	}
	else if (ft_strcmp(line, "HEIGHT:") == 0)
	{
		*step = 2;
		*i = 0;
		return (1);
	}
	else if (ft_strcmp(line, "OBJ:") == 0)
	{
		*step = 3;
		*i = 0;
		return (1);
	}
	return (0);
}

static	void	fill_tiles(t_data *data, char *filename)
{
	int		fd;
	char	*line;
	int		i;
	int		step;

	if ((fd = open(filename, O_RDONLY)) > 0)
	{
		step = 0;
		while (get_next_line(fd, &line) == 1)
		{
			if (detect_step(line, &i, &step))
			{
				if (step == 1)
					step_one(data, line, i);
				else if (step == 2)
					step_two(data, line, i);
				else if (step == 3)
					step_three(data, line, i);
				i++;
			}
			ft_strdel(&line);
		}
		ft_strdel(&line);
		close(fd);
	}
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
	data->game_state = GAME;
	data->map.name = ft_strjoin("maps/map", ft_itoa(map + 1));
	if (verify_file(data, data->map.name, &w, &h) == 0)
		usage(4);
	data->map.width = w;
	data->map.height = h;
	data->map.tiles = ft_memalloc(sizeof(t_tile*) * h);
	while (++i < h)
		data->map.tiles[i] = ft_memalloc(sizeof(t_tile) * w);
	fill_tiles(data, data->map.name);
	data->loading = 0;
}
