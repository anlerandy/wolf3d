/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tiles_steps.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 17:13:37 by acourtin          #+#    #+#             */
/*   Updated: 2018/03/04 21:13:46 by acourtin         ###   ########.fr       */
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
		if (line[j] == 'B')
			tex = BRICK;
		else if (line[j] == 'M')
			tex = METAL;
		else if (line[j] == 'S')
			tex = STONE;
		else
			tex = WOOD;
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

void		step_three(t_data *data, char *line, int i)
{
	int			j;
	t_entity	ent;

	j = 0;
	if (i >= data->map.h || data->map.w < (int)ft_strlen(line))
	{
		i >= data->map.h ? debug(data->debug, "Hauteur incorrecte de OBJ") :
		debug(data->debug, "Largeur incorrecte dans OBJ, ligne : ");
		data->map.w < (int)ft_strlen(line) ? debug(data->debug, ft_itoa(i)) : i;
		usage(4);
	}
	while (line[j])
	{
		if (line[j] == 'J')
		{
			ent = PLAYER_START;
			data->player.pos.x = j + 0.5;
			data->player.pos.y = i + 0.5;
			data->player.pos.z = 0;
		}
		else
			ent = NONE;
		data->map.tiles[i][j].entity = ent;
		j++;
	}
}
