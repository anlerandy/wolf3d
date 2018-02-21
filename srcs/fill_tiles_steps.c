/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tiles_steps.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 17:13:37 by acourtin          #+#    #+#             */
/*   Updated: 2018/02/21 12:07:10 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		step_one(t_data *data, char *line, int i)
{
	int			j;
	t_texture	tex;

	j = 0;
	while (line[j])
	{
		if (line[j] == '+')
			tex = WOOD;
		else
			tex = METAL;
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
	if (data->map.w != ft_strlen(line))
	{
		debug(data->debug, "Largeur incorrecte dans HEIGHT, ligne : ");
		debug(data->debug, ft_itoa(i));
		usage(4);
	}
	while (line[j])
	{
		if (line[j] != ' ')
			hgt = line[j] - 48;
		else
			hgt = 0;
		data->map.tiles[i][j].z = hgt;
		j++;
	}
}

void		step_three(t_data *data, char *line, int i)
{
	int			j;
	t_entity	ent;

	j = 0;
	while (line[j])
	{
		if (line[j] == 'J')
		{
			ent = PLAYER_START;
			data->player.pos.x = j + 0.5;
			data->player.pos.y = i + 0.5;
		}
		else
			ent = NONE;
		data->map.tiles[i][j].entity = ent;
		j++;
	}
}
