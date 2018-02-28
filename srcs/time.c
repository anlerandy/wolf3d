/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 20:49:39 by acourtin          #+#    #+#             */
/*   Updated: 2018/02/28 15:18:05 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int				get_actual_time(t_data *data)
{
	time_t		ltime;
	struct tm	*timeinfo;

	timeinfo = NULL;
	time(&ltime);
	timeinfo = localtime(&ltime);
	return (timeinfo->tm_sec);
}

void			loop_fps(t_data *data)
{
	static int	a_fps = 0;

	data->actual_time = get_actual_time(data);
	if (data->last_time != data->actual_time)
	{
		data->fps = a_fps;
		a_fps = 0;
		data->last_time = data->actual_time;
	}
	else
		a_fps++;
}
