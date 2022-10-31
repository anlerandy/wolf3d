/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 17:19:45 by alerandy          #+#    #+#             */
/*   Updated: 2021/11/17 14:37:12 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void	arrow_input(t_data *data, int key, int pressing)
{
	key == 65362 && pressing ? data->player.k_val.walk = 1 : 0;
	key == 65362 && !pressing ? data->player.k_val.walk = 0 : 0;
	key == 65364 && !pressing ? data->player.k_val.walk = 0 : 0;
	key == 65364 && pressing ? data->player.k_val.walk = -1 : 0;
	key == 65361 && pressing ? data->player.k_val.rot = 1 : 0;
	key == 65361 && !pressing ? data->player.k_val.rot = 0 : 0;
	key == 65363 && pressing ? data->player.k_val.rot = -1 : 0;
	key == 65363 && !pressing ? data->player.k_val.rot = 0 : 0;
	key == 65505 && pressing ? data->player.k_val.run = 1 : 0;
	key == 65505 && !pressing ? data->player.k_val.run = 0 : 1;
}

void		ft_player_input(t_data *data, int key, int pressing)
{
	arrow_input(data, key, pressing);
	key == 119 && pressing ? data->player.k_val.walk = 1 : 0;
	key == 119 && !pressing ? data->player.k_val.walk = 0 : 0;
	key == 115 && !pressing ? data->player.k_val.walk = 0 : 0;
	key == 115 && pressing ? data->player.k_val.walk = -1 : 0;
	key == 65293 && pressing ? data->player.k_val.run = 1 : 0;
	key == 65293 && !pressing ? data->player.k_val.run = 0 : 1;
	key == 97 && pressing ? data->player.k_val.rot = 1 : 0;
	key == 97 && !pressing ? data->player.k_val.rot = 0 : 0;
	key == 100 && pressing ? data->player.k_val.rot = -1 : 0;
	key == 100 && !pressing ? data->player.k_val.rot = 0 : 0;
	key == 32 && pressing ? data->player.k_val.fire = 1 : 0;
	key == 32 && !pressing ? data->player.k_val.fire = 0 : 0;
	key == 114 && pressing ? data->player.k_val.reload = 1 : 0;
	key == 114 && !pressing ? data->player.k_val.reload = 0 : 0;
	data->player.k_val.side = 0;
}
