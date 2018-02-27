/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 20:44:58 by acourtin          #+#    #+#             */
/*   Updated: 2018/02/27 20:23:32 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static int		check_z(t_data *data, t_ray *r, char *str)
{
//	ft_putendl("Verification de la case");

	if (r->y > data->map.h || r->y < 0 || r->x > data->map.w || r->x < 0)
	{
		if (data->debug)
		{
/*		ft_putendl("");
		ft_putendl(str);
		ft_putstr("Player.x = ");
		ft_putnbr(data->player.pos.x);
		ft_putstr(" ; x = ");
		ft_putnbr(r->x);
		ft_putstr(" ; Max map x = ");
		ft_putnbr(data->map.w);
		ft_putendl("");
		ft_putstr("Player.y = ");
		ft_putnbr(data->player.pos.y);
		ft_putstr(" ; y = ");
		ft_putnbr(r->y);
		ft_putstr(" ; Max map y = ");
		ft_putnbr(data->map.h);
		ft_putstr("\nCurrent rotation = ");
		ft_putnbr(data->player.rot);
		ft_putendl("");*/
		}
		return (-1);
	}
	if (data->map.tiles[(int)(r->y)][(int)(r->x)].z > 0)
	{
//		ft_putendl("Mur detecte");
		return (1);
	}
//	ft_putendl("Aucun mur");
	return (0);
}

static void		loop_rax2(t_data *data, t_ray *r, double a, int i)
{
	double		dir;
	int			c;

	while ((c = check_z(data, r, "Recherche par x sans y:")) == 0)
	{
		data->player.rot == 90 ? r->x++ : r->x--;
		r->depth++;
	}
	if (c == -1)
		r->depth = -42;
}

static void		loop_rax(t_data *data, t_ray *r, double a, int i)
{
	double		b;
	double		dir;
	int			c;

	dir = cos(((data->player.rot - 120) + (i * 60.0 / 1400.0)) / 180.0 * M_PI);
	b = data->player.pos.y - a * data->player.pos.x;
	while ((c = check_z(data, r, "Recherche par x :")) == 0)
	{
		dir >= 0 ? r->x++ : r->x--;
		r->y = a * r->x + b;
		r->depth = r->x - data->player.pos.x;
	if (data->debug && (int)((r->x * 4)) + ((int)((r->y * 4)) * 300) < 300 * 300\
			&& (int)((r->x * 4)) + ((int)((r->y * 4)) * 300) > 0)
		((int*)data->minimap.img)[(int)((r->x * 4)) \
			+ ((int)((r->y * 4)) * 300)] = 0x00FF0000;
	}
	if (c == -1)
		r->depth = -42;
	r->depth *= r->depth;
	r->depth += ((r->y - data->player.pos.y) * (r->y - data->player.pos.y));
	r->depth = sqrt(r->depth);
}

static void		loop_ray2(t_data *data, t_ray *r, double a, int i)
{
	int			c;

	while ((c = check_z(data, r, "Recherche par y sans x :")) == 0)
	{
		data->player.rot == 0 ? r->y++ : r->y--;
		r->depth++;
	}
	if (c == -1)
	{
		r->depth = -42;
		return ;
	}
}

static void		loop_ray(t_data *data, t_ray *r, double a, int i)
{
	double		b;
	double		dir;
	int			c;

	dir = sin(((data->player.rot - 120) + (i * 60.0 / 1400.0)) / 180.0 * M_PI);
	b = data->player.pos.y - a * data->player.pos.x;
	while ((c = check_z(data, r, "Recherche par y :")) == 0)
	{
		dir >= 0 ? r->y++ : r->y--;
		r->x = (r->y - b) / a;
		r->depth = r->y - data->player.pos.y;
	if (data->debug && (int)((r->x * 4)) + ((int)((r->y * 4)) * 300) < 300 * 300\
			&& (int)((r->x * 4)) + ((int)((r->y * 4)) * 300) > 0)
		((int*)data->minimap.img)[(int)((r->x * 4)) \
			+ ((int)((r->y * 4)) * 300)] = 0x0000FF00;
	}
	if (c == -1)
	{
		r->depth = -42;
		return ;
	}
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

	rot = (data->player.rot - 120) + (i * 60.0 / 1400.0);
	rot < 0 ? rot += 360 : 0;
	teta = tan(rot / 180.0 * M_PI);
//	printf("\n%f\n", rot);
	r.x = (data->player.pos.x - 0);
	r2.x = (data->player.pos.x - 0);
	r.y = (data->player.pos.y - 0);
	r2.y = (data->player.pos.y - 0);
	printf("\n%f , %f\n", r.x, data->player.pos.x);
	printf("%f , %f\n", r.y, data->player.pos.y);
/*	r.x < 0 ? r.x = 0 : 0;
	r.y < 0 ? r.y = 0 : 0;
	r.x > 99 ? r.x = 99 : 0;
	r.y > 99 ? r.y = 99 : 0;*/
	if (rot == 90 || rot == 270)
		loop_ray2(data, &r2, teta, i);
	else if (rot != 0 && rot != 180)
		loop_ray(data, &r2, teta, i);
	else
		r2.depth = -42;
	if (rot == 0 || rot == 180)
		loop_rax2(data, &r, teta, i);
	else if ((rot != 90 && rot != 270))
		loop_rax(data, &r, teta, i);
	else
		r.depth = -42;
	if (r2.depth > -42 && r.depth > -42)
	{
/*		ft_putnbr(r.depth);
		ft_putstr(" : ");
		ft_putnbr(r2.depth);
		ft_putendl("");*/
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
