/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 14:08:23 by acourtin          #+#    #+#             */
/*   Updated: 2018/02/18 14:08:29 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

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
