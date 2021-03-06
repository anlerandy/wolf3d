/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuits <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 17:56:02 by esuits            #+#    #+#             */
/*   Updated: 2019/04/24 17:56:04 by esuits           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

t_vec2	sub_v2(t_vec2 a, t_vec2 b)
{
	t_vec2 c;

	c.x = a.x - b.x;
	c.y = a.y - b.y;
	return (c);
}

t_vec3	sub_v3(t_vec3 a, t_vec3 b)
{
	t_vec3 c;

	c.x = a.x - b.x;
	c.y = a.y - b.y;
	c.z = a.z - b.z;
	return (c);
}

t_mat	sub_mat(t_mat a, t_mat b)
{
	int			i;
	int			j;
	int			k;
	t_mat		c;

	if ((a.w != b.h) || !((c = init_mat(a.h, b.w)).mat))
		return ((t_mat){-1, -1, NULL});
	i = -1;
	while (++i < a.w && (j = -1))
		while (++j < b.h && (k = -1))
			c.mat[i][j] = a.mat[i][j] - b.mat[i][j];
	return (c);
}

t_vec	sub_v(t_vec a, t_vec b)
{
	t_vec	c;
	int		i;

	if ((a.size != b.size) || (!(c = init_v(a.size)).vec))
		return ((t_vec){-1, NULL});
	i = -1;
	while (++i)
		c.vec[i] = a.vec[i] - b.vec[i];
	return (c);
}
