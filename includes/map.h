/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 14:08:23 by acourtin          #+#    #+#             */
/*   Updated: 2018/03/06 15:22:21 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# define DPI_FAC 30
# define MINI_OPAC 0x4F000000

typedef struct		s_wall
{
	double			wheight;
	double			mxheight;
	int				color;
	int				currpix;
	int				texpix;
	int				walpix;
}					t_wall;

typedef enum		e_texture
{
	BRICK,
	WOOD,
	STONE,
	METAL,
	COLORS,
	MULTI
}					t_texture;

typedef enum		e_entity
{
	NONE,
	START
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
