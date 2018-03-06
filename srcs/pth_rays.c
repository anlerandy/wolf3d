/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pth_rays.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 15:27:14 by alerandy          #+#    #+#             */
/*   Updated: 2018/03/06 21:56:58 by acourtin         ###   ########.fr       */
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
		if (info->data->player.r[k].tx == WOOD && info->data->player.fired == \
			1 && k == 700 && info->data->player.r[k].depth < 2)
			info->data->map.tiles[(int)(info->data->player.r[k].y)][\
				(int)(info->data->player.r[k].x)].z = 0;
		if (info->data->player.r[k].depth >= 0)
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
	redo = 0;
	bug = 0;
	data->debug ? bug = data->debug : 0;
	data->debug ? redo = data->debug : 0;
	data->debug2 = data->debug;
	while (++i < THREADS)
	{
		thr[i].data = data;
		thr[i].i = i;
		data->debug = 0;
		i == THREADS ? thr[i].data->debug = bug : 0;
		pthread_create(&t[i], NULL, pth_rays, (void*)&thr[i]);
		i == THREADS ? bug = 0 : 0;
	}
	i = -1;
	while (++i < THREADS)
		pthread_join(t[i], NULL);
	redo ? data->debug = redo : 0;
}
