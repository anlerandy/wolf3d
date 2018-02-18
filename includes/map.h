/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 14:08:23 by acourtin          #+#    #+#             */
/*   Updated: 2018/02/18 16:44:45 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef enum		e_texture
{
	BOIS,
	PIERRE,
	METAL
}					t_texture;

typedef enum		e_entity
{
	NONE,
	PLAYER_START
}					t_entity;

typedef struct		s_tile
{
	int				height;
	t_texture		texture;
	t_entity		entity;
}					t_tile;

typedef struct		s_map
{
	char			*name;
	t_tile			**tiles;
	int				width;
	int				height;
}					t_map;

#endif
