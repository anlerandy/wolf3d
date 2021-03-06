/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 21:04:20 by alerandy          #+#    #+#             */
/*   Updated: 2018/03/13 21:57:18 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		get_size(t_data *data, char *line, int *w, int *h)
{
	*h += 1;
	if (!*w)
		*w = (int)ft_strlen(line);
	if (*w > 74 || *h > 74)
		usage(11);
	if (*w != (int)ft_strlen(line))
	{
		debug(data->debug, "Largeur incorrecte dans TEXTURE, ligne : ");
		debug(data->debug, ft_itoa(*h));
		usage(4);
	}
}

static int		verify_file(t_data *data, char *filename, int *w, int *h)
{
	t_verifyfile	v;

	v.step = 0;
	!(v.maxstep = 0) ? debug(data->debug, "Vérification de la map.") : 0;
	if ((v.fd = open(filename, O_RDONLY)) > 0)
	{
		while (++v.maxstep && get_next_line(v.fd, &v.line) == 1)
		{
			if (ft_strcmp(v.line, "TEXTURE:") == 0 && v.step == 0)
				v.step = 1;
			else if (ft_strcmp(v.line, "HEIGHT:") == 0 && v.step == 1)
				v.step = 2;
			else if (ft_strcmp(v.line, "OBJ:") == 0 && v.step == 2)
				v.step = 3;
			else if (v.step == 1)
				get_size(data, v.line, w, h);
			ft_strdel(&v.line);
			v.maxstep > 10000 ? usage(12) : 0;
		}
		ft_strdel(&v.line);
		close(v.fd);
	}
	else
		usage(6);
	return (v.step == 3);
}

static int		detect_step(t_data *data, char *line, int *i, int *step)
{
	if (ft_strcmp(line, "TEXTURE:") == 0 || ft_strcmp(line, "HEIGHT:") == 0
	|| ft_strcmp(line, "OBJ:") == 0)
	{
		debug(data->debug, "Recuperation des : ");
		debug(data->debug, line);
		ft_strcmp(line, "TEXTURE:") == 0 ? *step = 1 : 0;
		ft_strcmp(line, "HEIGHT:") == 0 ? *step = 2 : 0;
		ft_strcmp(line, "OBJ:") == 0 ? *step = 3 : 0;
		if (*step == 2)
			data->map.h = *i;
		if (*step == 3)
			if (*i != data->map.h)
			{
				debug(data->debug, "Hauteur incorrecte de HEIGHT : ");
				debug(data->debug, "Plus petite.");
				usage(4);
			}
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
		init_tiles(data, &step);
		while (get_next_line(fd, &line) == 1)
		{
			if (detect_step(data, line, &i, &step) == 0)
			{
				if (step == 1)
					step_one(data, line, i);
				else if (step == 2)
					step_two(data, line, i);
				else if (step == 3)
					step_three(data, line);
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
	int		h;
	int		w;
	char	*mapid;

	h = 0;
	w = 0;
	mapid = ft_itoa(map + 1);
	debug(data->debug, "Chargement de la map : ");
	debug(data->debug, mapid);
	data->game_state = GAME;
	data->map.name = ft_strjoin("maps/map", mapid);
	free(mapid);
	mapid = ft_strjoin(data->env, data->map.name);
	ft_strdel(&(data->map.name));
	data->map.name = ft_strdup(mapid);
	free(mapid);
	if (verify_file(data, data->map.name, &w, &h) == 0)
		usage(8);
	(data->map.w = w) == 0 ? usage(10) : 0;
	(data->map.h = h) == 0 ? usage(10) : 0;
	malloc_tiles(data, h, w);
	fill_tiles(data, data->map.name);
	data->loading != 3 ? init_player(data) : 0;
	data->loading != 3 ? draw_map(data) : 0;
	data->loading = 0;
}
