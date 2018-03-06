/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pth_rays.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 15:27:14 by alerandy          #+#    #+#             */
/*   Updated: 2018/03/06 16:55:43 by alerandy         ###   ########.fr       */
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
	while (++j < 1400 / THREADS)
	{
		k = j * THREADS + info->i;
		send_ray(info->data, k);
		draw_wall(info->data, info->data->player.r[k], k);
	}
	return (NULL);
}

void		create_threads(t_data *data)
{
	t_pth_inf	thr[THREADS];
	pthread_t	t[THREADS];
	int			i;
	int			bug;
	int			redo;

	i = -1;
	data->debug ? bug = 1 : 0;
	data->debug ? redo = 1 : 0;
	while (++i < THREADS)
	{
		thr[i].data = data;
		thr[i].i = i;
		thr[i].data->debug = bug;
		pthread_create(&t[i], NULL, pth_rays, (void*)&thr[i]);
		bug = 0;
	}
	i = -1;
	while (++i < THREADS)
		pthread_join(t[i], NULL);
	redo ? data->debug = redo : 0;
}
