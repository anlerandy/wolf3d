/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tiles_steps.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 17:13:37 by acourtin          #+#    #+#             */
/*   Updated: 2018/03/06 15:07:09 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "wolf.h"

void		step_one(t_data *data, char *line, int i)
{
	int			j;
	t_texture	tex;

	j = 0;
	while (line[j])
	{
		if (line[j] == 'B')
			tex = BRICK;
		else if (line[j] == 'M')
			tex = METAL;
		else if (line[j] == 'S')
			tex = STONE;
		else if (line[j] == 'W')
			tex = WOOD;
		else if (line[j] == 'R')
			tex = MULTI;
		else
			tex = COLORS;
		data->map.tiles[i][j].texture = tex;
		j++;
	}
}

void		step_two(t_data *data, char *line, int i)
{
	int j;
	int hgt;

	j = 0;
	if (i >= data->map.h)
	{
		debug(data->debug, "Hauteur incorrecte de HEIGHT : Trop grande.");
		usage(4);
	}
	if (data->map.w != (int)ft_strlen(line))
	{
		debug(data->debug, "Largeur incorrecte dans HEIGHT, ligne : ");
		debug(data->debug, ft_itoa(i));
		usage(4);
	}
	while (line[j])
	{
		if (ft_isdigit(line[j]))
			hgt = line[j] - 48;
		else
			hgt = 0;
		data->map.tiles[i][j].z = hgt;
		j++;
	}
}

void		step_three(t_data *data, char *line)
{
	char		**tab;
	int			i;

	i = 0;
	tab = ft_strsplit(line, '|');
	while (tab[i])
		i++;
	if (i == 3 || i == 4)
	{
		if (tab[0][0] == 'J')
		{
			data->player.pos.x = ft_atoi(tab[1]);
			data->player.pos.y = ft_atoi(tab[2]);
			if (i == 4)
				data->player.rot = ft_atoi(tab[3]);
		}
	}
}
