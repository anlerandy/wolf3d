/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 21:04:20 by alerandy          #+#    #+#             */
/*   Updated: 2018/02/18 03:06:40 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	map(t_data *data, int map)
{
	debug(data->debug, "Chargement de la map.");
	sleep(1);
	data->loading = 0;
	data->game_state = GAME;
}
