/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 14:08:23 by acourtin          #+#    #+#             */
/*   Updated: 2022/10/31 15:17:11 by alerandy         ###   ########.fr       */
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
	BRICK = 0,
	WOOD = 1,
	STONE = 2,
	METAL = 3,
	BREAK = 4,
	COLORS = 5,
	MULTI = 6
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

typedef enum		e_skybox
{
	DAY,
	NIGHT
}					t_skybox;

typedef struct		s_map
{
	char			*name;
	t_tile			**tiles;
	int				w;
	int				h;
	t_skybox		t;
}					t_map;

typedef struct		s_col
{
	int				r;
	int				g;
	int				b;
}					t_col;

#endif
