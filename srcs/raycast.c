/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 20:44:58 by acourtin          #+#    #+#             */
/*   Updated: 2018/03/01 03:36:21 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static int		check_z(t_data *data, t_ray *ray, int dir, int i)
{
	t_ray		r;

	r.x = ray->x;
	r.y = ray->y;
	if (i == 1 && r.x != data->player.pos.x)
		dir == 0 ? r.x-- : r.x;
	else if (i == 2)
		dir == 1 ? r.y : r.y--;
	if (r.y > data->map.h || r.y < 0 || r.x > data->map.w || r.x < 0)
		return (-1);
	if (data->map.tiles[(int)(r.y)][(int)(r.x)].z > 0)
		return (1);
	return (0);
}

static void		loop_rax2(t_data *data, t_ray *r, t_ray info, int i)
{
	int			c;

	while ((c = check_z(data, r, (info.x == 0), 1)) == 0)
	{
		info.x == 0 ? r->x++ : r->x--;
		r->depth == -1 ? r->depth = r->x - data->player.pos.x + 2 : r->depth++;
	}
	c == -1 ? r->depth = -42 : 0;
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
	while ((c = check_z(data, r, dir > 0, 1)) == 0)
	{
		dir >= 0 ? r->x++ : r->x--;
		r->y = a * r->x + b;
		r->depth = r->x - data->player.pos.x;
	if (data->debug && (int)((r->x * 4)) + ((int)((r->y * 4)) * 300) < \
			300 * 300 && (int)((r->x * 4)) + ((int)((r->y * 4)) * 300) > 0)
		((int*)data->minimap.img)[(int)((r->x * 4)) \
			+ ((int)((r->y * 4)) * 300)] = 0x00FF0000;
	}
	c == -1 ? r->depth = -42 : 0;
	if (c == -1)
		return ;
	r->depth *= r->depth;
	r->depth += ((r->y - data->player.pos.y) * (r->y - data->player.pos.y));
	r->depth = sqrt(r->depth);
}

static void		loop_ray2(t_data *data, t_ray *r, t_ray info, int i)
{
	int			c;

	while ((c = check_z(data, r, (info.x == 270), 2)) == 0)
	{
		info.x == 90 ? r->y++ : r->y--;
		r->depth == -1 ? r->depth = r->y - data->player.pos.y - 1 : r->depth++;
	}
	c == -1 ? r->depth = -42 : 0;
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
	while ((c = check_z(data, r, dir > 0, 2)) == 0)
	{
		dir >= 0 ? r->y++ : r->y--;
		r->x = (r->y - b) / a;
		r->depth = r->y - data->player.pos.y;
		if (data->debug && (int)(((r->x * 4)) + ((r->y * 4) * 300)) < \
				300 * 300 && (int)((r->x * 4) + ((r->y * 4) * 300)) > 0)
			((int*)data->minimap.img)[(int)((r->x * 4)) \
				+ ((int)((r->y * 4)) * 300)] = 0x0000FF00;
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
	double	teta;
	double	rot;
	t_ray	info;

	data->player.r[i].depth = -1;
	rot = ((data->player.rot - 30) + (i * 60.0 / 1400.0));
	rot < 0 ? rot += 360.0: 0;
	teta = tan(rot / 180.0 * M_PI);
	info.x = rot;
	info.y = teta;
//	r.x = cos(rot / 180.0 * M_PI) >= 0 ? (int)(data->player.pos.x) : (int)(data->player.pos.x - 1);
//	r2.x = cos(rot / 180.0 * M_PI) >= 0 ? (int)(data->player.pos.x) : (int)(data->player.pos.x - 1);
//	r.y = sin(rot / 180.0 * M_PI) >= 0 ? (int)(data->player.pos.y) : (int)(data->player.pos.y - 1);
//	r2.y = sin(rot / 180.0 * M_PI) >= 0 ? (int)(data->player.pos.y) : (int)(data->player.pos.y - 1);
	r.x = (int)(data->player.pos.x);
	r2.x = (int)(data->player.pos.x);
	r.y = (int)(data->player.pos.y);
	r2.y = (int)(data->player.pos.y);
	r.depth = -1;
	r2.depth = -1;
	printf("\nPOSX : %f ; POSY : %f\n", data->player.pos.x, data->player.pos.y);
	printf("verefX : %f ; verefY : %f\n", r.x, r.y);
//	if (rot == 0 || rot == 180)
//		loop_rax2(data, &r, info, i);
//	else if ((rot != 90 && rot != 270))
		loop_rax(data, &r, info, i);
//	else
//		r.depth = -42;
//	if (rot == 90 || rot == 270)
//		loop_ray2(data, &r2, info, i);
//	else if (rot != 0 && rot != 180)
		loop_ray(data, &r2, info, i);
//	else
//		r2.depth = -42;
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
	}
	else if (r2.depth == -42)
	{
		data->player.r[i].depth = r.depth;
		data->player.r[i].x = r.x;
		data->player.r[i].y = r.y;
	}
}
