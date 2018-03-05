/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pth_rays.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 15:27:14 by alerandy          #+#    #+#             */
/*   Updated: 2018/03/05 16:21:22 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		*pth_rays(void *param)
{
	t_pth_inf	*info;
	t_data		*data;
	int			i;

	info = (t_pth_inf*)(param);
	data = info->data;
	i = info->i;
	send_ray(data, i);
	draw_wall(data, data->player.r[i], i);
	pthread_exit(NULL);
}
