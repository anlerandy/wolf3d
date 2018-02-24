/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 17:19:45 by alerandy          #+#    #+#             */
/*   Updated: 2018/02/23 18:49:49 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void	arrow_input(t_data *data, int key, int pressing)
{
	key == KEY_UP && pressing ? data->player.k_val.walk = 1 : 0;
	key == KEY_UP && !pressing ? data->player.k_val.walk = 0 : 0;
	key == KEY_DOWN && !pressing ? data->player.k_val.walk = 0 : 0;
	key == KEY_DOWN && pressing ? data->player.k_val.walk = -1 : 0;
	key == KEY_LEFT && pressing ? data->player.k_val.rot = 1 : 0;
	key == KEY_LEFT && !pressing ? data->player.k_val.rot = 0 : 0;
	key == KEY_RIGHT && pressing ? data->player.k_val.rot = -1 : 0;
	key == KEY_RIGHT && !pressing ? data->player.k_val.rot = 0 : 0;
	key == KEY_SHIFT_RIGHT && pressing ? data->player.k_val.run = 1 : 0;
	key == KEY_SHIFT_RIGHT && !pressing ? data->player.k_val.run = 0 : 1;
}

void		ft_player_input(t_data *data, int key, int pressing)
{
	arrow_input(data, key, pressing);
	key == KEY_W && pressing ? data->player.k_val.walk = 1 : 0;
	key == KEY_W && !pressing ? data->player.k_val.walk = 0 : 0;
	key == KEY_S && !pressing ? data->player.k_val.walk = 0 : 0;
	key == KEY_S && pressing ? data->player.k_val.walk = -1 : 0;
	key == KEY_SHIFT_LEFT && pressing ? data->player.k_val.run = 1 : 0;
	key == KEY_SHIFT_LEFT && !pressing ? data->player.k_val.run = 0 : 1;
	key == KEY_A && pressing ? data->player.k_val.rot = 1 : 0;
	key == KEY_A && !pressing ? data->player.k_val.rot = 0 : 0;
	key == KEY_D && pressing ? data->player.k_val.rot = -1 : 0;
	key == KEY_D && !pressing ? data->player.k_val.rot = 0 : 0;
	key == KEY_SPACEBAR && pressing ? data->player.k_val.fire = 1 : 0;
	key == KEY_SPACEBAR && !pressing ? data->player.k_val.fire = 0 : 0;
	data->player.k_val.side = 0;
}
