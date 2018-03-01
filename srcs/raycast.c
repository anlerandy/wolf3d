/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 20:44:58 by acourtin          #+#    #+#             */
/*   Updated: 2018/03/01 06:50:12 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static int		check_z(t_data *data, t_ray *ray, int dir, int i)
{
	t_ray		r;

	r.x = ray->x;
	r.y = ray->y;
	if (i == 1)
		dir == 0 ? r.x-- : (r.x = (int)r.x);
	else if (i == 2)
		dir == 0 ?  r.y-- : r.y;
	if (r.y >= data->map.h || r.y < 0 || r.x >= data->map.w || r.x < 0)
		return (-1);
	if (data->map.tiles[(int)(r.y)][(int)(r.x)].z > 0)
	{
		i == 2 && dir == 1 ? ray->dir = NORTH : 0;
		i == 2 && dir == 0 ? ray->dir = SOUTH : 0;
		i == 1 && dir == 1 ? ray->dir = EAST : 0;
		i == 1 && dir == 0 ? ray->dir = WEST : 0;
		return (1);
	}
	return (0);
}

static void		loop_rax(t_data *data, t_ray *r, t_ray info, int i)
{
	double		b;
	double		dir;
	int			c;
	double		a;

	a = info.y;
	dir = cos(info.x / 180.0 * M_PI);
	b = data->player.pos.y - a * data->player.pos.x;
	while ((c = check_z(data, r, dir >= 0, 1)) == 0)
	{
	if (data->debug && (int)((r->x * 4)) + ((int)((r->y * 4)) * 300) < \
			300 * 300 && (int)((r->x * 4)) + ((int)((r->y * 4)) * 300) > 0)
		((int*)data->minimap.img)[(int)((r->x * 4)) \
			+ ((int)((r->y * 4)) * 300)] = 0x0FFF0000;
		dir >= 0 ? r->x++ : r->x--;
		r->y = a * r->x + b;
		r->depth = r->x - data->player.pos.x;
	}
	c == -1 ? r->depth = -42 : 0;
	if (c == -1)
		return ;
	r->depth *= r->depth;
	r->depth += ((r->y - data->player.pos.y) * (r->y - data->player.pos.y));
	r->depth = sqrt(r->depth);
}

static void		loop_ray(t_data *data, t_ray *r, t_ray info, int i)
{
	double		b;
	double		dir;
	int			c;
	double		a;

	a = info.y;
	dir = sin(info.x / 180.0 * M_PI);
	b = data->player.pos.y - a * data->player.pos.x;
	while ((c = check_z(data, r, dir >= 0, 2)) == 0)
	{
		if (data->debug && (int)(((r->x * 4)) + ((r->y * 4) * 300)) < \
				300 * 300 && (int)((r->x * 4) + ((r->y * 4) * 300)) > 0)
			((int*)data->minimap.img)[(int)((r->x * 4) \
				+ ((r->y * 4) * 300))] = 0x0F00FF00;
		dir >= 0 ? r->y++ : r->y--;
		r->x = (r->y - b) / a;
		r->depth = r->y - data->player.pos.y;
	}
	c == -1 ? r->depth = -42 : 0;
	if (c == -1)
		return ;
	r->depth *= r->depth;
	r->depth += ((r->x - data->player.pos.x) * (r->x - data->player.pos.x));
	r->depth = sqrt(r->depth);
}

void			send_ray(t_data *data, int i)
{
	t_ray	r;
	t_ray	r2;
	double	rot;
	t_ray	info;
	t_ray	dir;

	data->player.r[i].depth = -1;
	rot = ((data->player.rot - 30) + (i * 60.0 / 1400.0));
	rot < 0 ? rot += 360.0: 0;
	info.y = tan(rot / 180.0 * M_PI);
	info.x = rot;
	dir.x = cos(info.x / 180.0 * M_PI);
	dir.y = sin(info.x / 180.0 * M_PI);
	r.x = dir.x >= 0 ? (int)(data->player.pos.x) : (int)(data->player.pos.x + 1);
	r2.x = dir.x >= 0 ? (int)(data->player.pos.x) : (int)(data->player.pos.x);
	r.y = dir.y >= 0 ? (int)(data->player.pos.y) : (int)(data->player.pos.y);
	r2.y = dir.y >= 0 ? (int)(data->player.pos.y) : (int)(data->player.pos.y + 1);
	r.depth = -1;
	r2.depth = -1;
	loop_rax(data, &r, info, i);
	loop_ray(data, &r2, info, i);
	if (r2.depth > -42 && r.depth > -42)
	{
		r.depth < r2.depth ? r2.depth = -42 : 0;
		r.depth > r2.depth && r2.depth > -42 ? r.depth = -42 : 0;
	}
	if (r2.depth == -42 && r.depth == -42)
		usage(7);
	if (r.depth == -42)
	{
		data->player.r[i].depth = r2.depth;
		data->player.r[i].x = r2.x;
		data->player.r[i].y = r2.y;
		data->player.r[i].dir = r2.dir;
	}
	else if (r2.depth == -42)
	{
		data->player.r[i].depth = r.depth;
		data->player.r[i].x = r.x;
		data->player.r[i].y = r.y;
		data->player.r[i].dir = r.dir;
	}
}
