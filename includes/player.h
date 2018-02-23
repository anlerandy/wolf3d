/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 21:03:04 by acourtin          #+#    #+#             */
/*   Updated: 2018/02/23 18:04:41 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# define PLAYER_SPEED 0.5
# define PLAYER_ROT 4

typedef struct			s_pos
{
	double				x;
	double				y;
	double				z;
}						t_pos;

typedef struct			s_ray
{
	double				x;
	double				y;
	double				depth;
}						t_ray;

typedef struct			s_player
{
	int					hp;
	int					amo;
	int					end;
	double				rot;
	double				rotx;
	double				roty;
	t_pos				pos;
	t_ray				r[1400];
}						t_player;

#endif
