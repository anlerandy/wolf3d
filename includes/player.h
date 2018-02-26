/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 21:03:04 by acourtin          #+#    #+#             */
/*   Updated: 2018/02/26 17:07:48 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# define PLAYER_SPEED 0.06
# define PLAYER_ROT 2
# define END_DECR 0.3
# define END_INCR 1
# define RECO_INCR 0.8
# define GUN_ANIM 3

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

typedef struct			s_input
{
	int					walk;
	int					run;
	int					rot;
	int					fire;
	int					side;
}						t_input;

typedef struct			s_player
{
	int					hp;
	int					amo;
	int					fired;
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
