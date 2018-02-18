/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 13:23:26 by acourtin          #+#    #+#             */
/*   Updated: 2018/02/18 13:33:46 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPS_H
# define MAPS_H

typedef enum		e_tile_type
{
	FLOOR,
	WALL,
	PLAYER_START
}					t_tile_type;

typedef struct		s_tile
{
	t_tile_type		type;
	int				collision;
}					t_tile;

typedef struct		s_map
{
	char			*name;
	t_tile			tiles[64][64];
}					t_map;

#endif
