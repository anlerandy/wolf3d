/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pth_rays.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 15:27:14 by alerandy          #+#    #+#             */
/*   Updated: 2018/03/05 20:21:43 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		*pth_rays(void *param)
{
	t_pth_inf	*info;
	int			j;
	int			k;

	j = -1;
	info = (t_pth_inf*)param;
	while (++j < 20)
	{
		k = j * 70 + info->i;
		send_ray(info->data, k);
		draw_wall(info->data, info->data->player.r[k], k);
	}
	return (NULL);
}

void		create_threads(t_data *data)
{
	t_pth_inf	thr[70];
	pthread_t	t[70];
	int			i;

	i = -1;
	while (++i < 70)
	{
		thr[i].data = data;
		thr[i].i = i;
		pthread_create(&t[i], NULL, pth_rays, (void*)&thr[i]);
	}
	i = -1;
	while (++i < 70)
		pthread_join(t[i], NULL);
}
