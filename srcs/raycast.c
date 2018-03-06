/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 20:44:58 by acourtin          #+#    #+#             */
/*   Updated: 2018/03/06 18:53:47 by alerandy         ###   ########.fr       */
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
		dir == 0 ? r.y-- : r.y;
	if (r.y >= data->map.h || r.y < 0 || r.x >= data->map.w || r.x < 0)
		return (-1);
	if (data->map.tiles[(int)(r.y)][(int)(r.x)].z > 0)
	{
		i == 2 && dir == 0 ? ray->dir = NORTH : 0;
		i == 2 && dir == 1 ? ray->dir = SOUTH : 0;
		i == 1 && dir == 0 ? ray->dir = EAST : 0;
		i == 1 && dir == 1 ? ray->dir = WEST : 0;
		ray->y = r.y;
		ray->x = r.x;
		ray->tx = data->map.tiles[(int)(r.y)][(int)(r.x)].texture;
		return (1);
	}
	return (0);
}

static void		loop_rax(t_data *data, t_ray *r, t_ray info)
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
		if (data->debug2 && (int)((r->x * 4)) + ((int)((r->y * 4)) * 300) < \
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

static void		loop_ray(t_data *data, t_ray *r, t_ray info)
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
		if (data->debug2 && (int)(((r->x * 4)) + ((r->y * 4) * 300)) < \
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

static void		set_ray(t_data *data, t_ray *r, t_ray *r2, t_ray *info)
{
	t_ray	dir;

	info->x = ((data->player.rot - 30) + (info->depth * 60 / 1400.0));
	info->x < 0 ? info->x += 360.0 : 0;
	info->y = tan(info->x / 180.0 * M_PI);
	dir.x = cos(info->x / 180.0 * M_PI);
	dir.y = sin(info->x / 180.0 * M_PI);
	r->x = dir.x >= 0 ? (int)(data->player.pos.x) : (int)(data->player.pos.x \
		+ 1);
	r2->x = dir.x >= 0 ? (int)(data->player.pos.x) : (int)(data->player.pos.x);
	r->y = dir.y >= 0 ? (int)(data->player.pos.y) : (int)(data->player.pos.y);
	r2->y = dir.y >= 0 ? (int)(data->player.pos.y) : (int)(data->player.pos.y \
		+ 1);
	r->depth = -1;
	r2->depth = -1;
	data->player.r[(int)(info->depth)].depth = -1;
	loop_rax(data, r, *info);
	loop_ray(data, r2, *info);
	if (r2->depth > -42 && r->depth > -42)
	{
		r->depth < r2->depth ? r2->depth = -42 : 0;
		r->depth > r2->depth && r2->depth > -42 ? r->depth = -42 : 0;
	}
}

void			send_ray(t_data *data, int i)
{
	t_ray	r;
	t_ray	r2;
	t_ray	info;

	info.depth = i;
	set_ray(data, &r, &r2, &info);
	if (r2.depth == -42 && r.depth == -42)
		data->player.r[i].depth = -1;
	data->player.r[i].x = r.depth == -42 ? r2.x : r.x;
	data->player.r[i].y = r.depth == -42 ? r2.y : r.y;
	data->player.r[i].dir = r.depth == -42 ? r2.dir : r.dir;
	info.x = info.x - data->player.rot;
	data->player.r[i].depth = r.depth == -42 ? r2.depth * \
							cos(info.x / 180 * M_PI) : r.depth * \
							cos(info.x / 180 * M_PI);
	data->player.r[i].tx = r.depth == -42 ? r2.tx : r.tx;
	if (r2.depth != -42 || r.depth != -42)
		data->player.r[i].maph = r.depth == -42 ? \
			data->map.tiles[(int)r2.y][(int)r2.x].z : \
			data->map.tiles[(int)r.y][(int)r.x].z;
}
