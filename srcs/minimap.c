/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 10:51:51 by acourtin          #+#    #+#             */
/*   Updated: 2018/02/21 10:56:46 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void			draw_minimap(t_data *data)
{
	data->minimap.img = ft_intset(data->minimap.img, 0x00000000, 300 * 300);
	((int*)data->minimap.img)[310] = 0x00FF0000;
}
