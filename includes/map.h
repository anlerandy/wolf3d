/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 14:08:23 by acourtin          #+#    #+#             */
/*   Updated: 2018/02/26 18:18:50 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# define DPI_FAC 60
# define MINI_OPAC 0x4F000000

typedef enum		e_texture
{
	WOOD,
	STONE,
	METAL
}					t_texture;

typedef enum		e_entity
{
	NONE,
	PLAYER_START
}					t_entity;

typedef struct		s_tile
{
	int				z;
	t_texture		texture;
	t_entity		entity;
}					t_tile;

typedef struct		s_map
{
	char			*name;
	t_tile			**tiles;
	int				w;
	int				h;
}					t_map;

#endif
