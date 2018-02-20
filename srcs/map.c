/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 21:04:20 by alerandy          #+#    #+#             */
/*   Updated: 2018/02/18 21:40:16 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		get_size(t_data *data, char *line, int *w, int *h)
{
	*h += 1;
	if (!*w)
		*w = ft_strlen(line);
	if (*w != ft_strlen(line))
	{
		debug(data->debug, "Largeur incorrecte dans TEXTURE, ligne : ");
		debug(data->debug, ft_itoa(*h));
		usage(4);
	}
}

static int		verify_file(t_data *data, char *filename, int *w, int *h)
{
	int		fd;
	char	*line;
	int		step;

	step = 0;
	debug(data->debug, "Vérification de la map.");
	if ((fd = open(filename, O_RDONLY)) > 0)
	{
		while (get_next_line(fd, &line) == 1)
		{
			if (ft_strcmp(line, "TEXTURE:") == 0 && step == 0)
				step = 1;
			else if (ft_strcmp(line, "HEIGHT:") == 0 && step == 1)
				step = 2;
			else if (ft_strcmp(line, "OBJ:") == 0 && step == 2)
				step = 3;
			else if (step == 1)
				get_size(data, line, w, h);
			ft_strdel(&line);
		}
		ft_strdel(&line);
		close(fd);
	}
	if (step == 3)
		return (1);
	else
		return (0);
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
		init_tiles(data);
		while (get_next_line(fd, &line) == 1)
		{
			if (detect_step(line, &i, &step) == 0)
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
	int		i;
	int		h;
	int		w;
	char	*mapid;

	i = -1;
	h = 0;
	w = 0;
	mapid = ft_itoa(map + 1);
	debug(data->debug, "Chargement de la map : ");
	debug(data->debug, mapid);
	data->game_state = GAME;
	data->map.name = ft_strjoin("maps/map", mapid);
	free(mapid);
	if (verify_file(data, data->map.name, &w, &h) == 0)
		usage(4);
	data->map.w = w;
	data->map.h = h;
	data->map.tiles = ft_memalloc(sizeof(t_tile*) * h);
	while (++i < h)
		data->map.tiles[i] = ft_memalloc(sizeof(t_tile) * w);
	fill_tiles(data, data->map.name);
	init_player(data);
	draw_map(data);
	data->loading = 0;
}
