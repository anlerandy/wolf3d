/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tiles_steps.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 17:13:37 by acourtin          #+#    #+#             */
/*   Updated: 2018/03/06 17:04:34 by acourtin         ###   ########.fr       */
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

/*
** La gestion des tailles de mur à été désactivé dans la fonction ci dessous.
** Pour réactiver, remplacer ligne 19 par hgt = line[j] - 48;
** Et retirer && line[j] == '9'.
*/

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
		if (ft_isdigit(line[j]) && line[j] == '9')
			hgt = '9' - 48;
		else
			hgt = 0;
		data->map.tiles[i][j].z = hgt;
		j++;
	}
}

static void	player_start(t_data *data, int i, char **tab)
{
	int		x;
	int		y;

	x = ft_atoi(tab[1]);
	y = ft_atoi(tab[2]);
	if (data->map.tiles[y][x].z == 0)
	{
		data->player.pos.x = x + 0.5;
		data->player.pos.y = y + 0.5;
		if (i == 4)
			data->player.rot = ft_atoi(tab[3]);
	}
	else
	{
		debug(data->debug, "Le joueur est dans un mur.");
		debug(data->debug, "Ligne : ");
		debug(data->debug, tab[1]);
		debug(data->debug, "Colonne : ");
		debug(data->debug, tab[2]);
		usage(5);
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
	if (i == 2 || i == 3 || i == 4)
	{
		if (tab[0][0] == 'J')
			player_start(data, i, tab);
		if (tab[0][0] == 'T')
			data->map.t = ft_atoi(tab[1]) == 0 ? DAY : NIGHT;
	}
	while (i >= 0)
	{
		free(tab[i--]);
	}
	free(tab);
}
