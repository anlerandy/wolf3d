/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 21:03:04 by acourtin          #+#    #+#             */
/*   Updated: 2018/02/27 17:51:21 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# define PLAYER_SPEED 0.06
# define PLAYER_ROT 2
# define END_DECR 0.3
# define END_INCR 1
# define RECO_INCR 0.8
# define GUN_ANIM 2

typedef struct			s_pos
{
	double				x;
	double				y;
	double				z;
}						t_pos;

typedef enum			e_dir
{
	VOID,
	WEST,
	EAST,
	NORTH,
	SOUTH
}						t_dir;

typedef struct			s_ray
{
	double				x;
	double				y;
	double				depth;
	t_dir				dir;
}						t_ray;

typedef struct			s_input
{
	int					walk;
	int					run;
	int					rot;
	int					fire;
	int					reload;
	int					side;
}						t_input;

typedef struct			s_player
{
	int					hp;
	int					amo;
	int					amo_chamber;
	int					fired;
	int					reloading;
	int					gun_frame;
	double				end;
	double				recover;
	double				rot;
	double				rotx;
	double				roty;
	t_pos				pos;
	t_ray				r[1400];
	t_input				k_val;
}						t_player;

#endif
