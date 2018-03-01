/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 17:18:38 by acourtin          #+#    #+#             */
/*   Updated: 2018/02/28 17:38:22 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void	dir_walls(t_data *data, t_ray *ray)
{
	if (data->map.tiles[(int)(ray->y + 0.02)][(int)ray->x].z == 0 \
			&& data->map.tiles[(int)(ray->y - 0.02)][(int)ray->x].z != 0 \
			&& data->map.tiles[(int)(ray->y - 0.04)][(int)(ray->x \
			- 0.04)].z != 0 && data->map.tiles[(int)(ray->y \
			- 0.04)][(int)(ray->x + 0.04)].z != 0)
			ray->dir = NORTH;
	if (data->map.tiles[(int)(ray->y + 0.02)][(int)ray->x].z != 0 \
			&& data->map.tiles[(int)(ray->y - 0.02)][(int)ray->x].z == 0 \
			&& data->map.tiles[(int)(ray->y + 0.04)][(int)(ray->x \
			- 0.04)].z != 0 && data->map.tiles[(int)(ray->y \
			+ 0.04)][(int)(ray->x + 0.04)].z != 0)
			ray->dir = SOUTH;
	if (data->map.tiles[(int)ray->y][(int)(ray->x + 0.02)].z != 0 \
			&& data->map.tiles[(int)ray->y][(int)(ray->x - 0.02)].z == 0 \
			&& data->map.tiles[(int)(ray->y + 0.04)][(int)(ray->x \
			+ 0.04)].z != 0 && data->map.tiles[(int)(ray->y \
			- 0.04)][(int)(ray->x + 0.04)].z != 0)
			ray->dir = EAST;
	if (data->map.tiles[(int)ray->y][(int)(ray->x + 0.02)].z == 0 \
			&& data->map.tiles[(int)ray->y][(int)(ray->x - 0.02)].z != 0 \
			&& data->map.tiles[(int)(ray->y + 0.04)][(int)(ray->x \
			- 0.04)].z != 0 && data->map.tiles[(int)(ray->y \
			- 0.04)][(int)(ray->x - 0.04)].z != 0)
			ray->dir = WEST;
}

void		draw_wall(t_data *data, t_ray ray, int slice)
{
	double	h;
	double	d;
	double	h2;
	t_ray	dist;
	int		color;
	int		color2;
	static t_xpm tex;
	static int s = 0;

	if (!s)
		tex = xpm_create(data, "./xpm/stone.xpm", 1400, 800);
	s = 1;
	h = 0;
	h2 = 1;
	dist.x = data->player.pos.x - ray.x;
	dist.y = data->player.pos.y - ray.y;
	d = sqrt(dist.x * dist.x + dist.y * dist.y);
	d < 1 ? d = 1 : 0;
	d = (400 / d);
	color =  0x00000000;
	ray.dir = VOID;
	dir_walls(data, &ray);
	ray.dir == WEST ? color = 0x00FF0000 : color;
	ray.dir == EAST ? color = 0x0000FF00 : color;
	ray.dir == NORTH ? color = 0x000000FF : color;
	ray.dir == SOUTH ? color = 0x00FFFF00 : color;
	color2 = color;
	while (h < d)
	{
		//color = tex.img[(int)((ray.x - (int)ray.x) * 1400 + (400 - h) * 400 / d + (h * 1400))];
		//color2 = tex.img[(int)((ray.x - (int)ray.x) * 1400 + (400 + (h + 1)) * 400 / d + (h * 1400))];
		if (ray.dir == NORTH)
		{
		if ((int)(slice + (((h * 200 / d) + (h * 200 / d)) * 1400)) < 1400 * 800)
			color = tex.img[(int)(slice + (((h * 200 / d) + (h * 200 / d)) * 1400))];
		//if ((int)(slice + ((((h + 1) * 200 / d) + ((h + 1) * 200 / d)) * 1400)) < 1400 * 800)
		//	color2 = tex.img[(int)(slice + ((((h + 1) * 200 / d) + ((h + 1) * 200 / d)) * 1400))];
		}
		((int*)data->frame.img)[1400 - slice + (((int)(data->win_h / 2) \
			- (int)h) * data->win_w)] = color;
		((int*)data->frame.img)[1400 - slice + (((int)(data->win_h / 2) \
			+ (int)(h + 1)) * data->win_w)] = color2;
		h += 1;
		h2 += 1;
	}
}
