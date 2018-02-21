/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 21:03:04 by acourtin          #+#    #+#             */
/*   Updated: 2018/02/21 12:39:10 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

typedef struct			s_pos
{
	double				x;
	double				y;
	double				z;
}						t_pos;

typedef struct			s_player
{
	int					hp;
	int					end;
	double				rot;
	double				rotx;
	double				roty;
	t_pos				pos;
}						t_player;

#endif
