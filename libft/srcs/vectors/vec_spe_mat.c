/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spe_mat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuits <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 17:56:38 by esuits            #+#    #+#             */
/*   Updated: 2019/04/24 17:56:39 by esuits           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

t_mat	init_id_mat(int w)
{
	t_mat	mat;
	int		i;

	if (w <= 0)
		return ((t_mat){-1, -1, NULL});
	if (!(mat.mat = ft_memalloc(w * sizeof(double*))))
		return ((t_mat){-1, -1, NULL});
	i = -1;
	while (++i < w)
		if (!(mat.mat[i] = ft_memalloc(w * sizeof(double))))
			return (free_mat_err(&mat, i));
	i = -1;
	while (++i < w)
		mat.mat[i][i] = 1;
	mat.w = w;
	mat.h = w;
	return (mat);
}

t_mat	rot_mat(t_vec3 v, double theta)
{
	t_mat rot;

	if ((rot = init_mat(3, 3)).w == -1)
		return (rot);
	rot.mat[0][0] = cos(theta) + v.x * v.x * (1 - cos(theta));
	rot.mat[1][1] = cos(theta) + v.y * v.y * (1 - cos(theta));
	rot.mat[2][2] = cos(theta) + v.z * v.z * (1 - cos(theta));
	rot.mat[0][1] = v.x * v.y * (1 - cos(theta)) - v.z * sin(theta);
	rot.mat[0][2] = v.x * v.z * (1 - cos(theta)) + v.y * sin(theta);
	rot.mat[1][0] = v.x * v.y * (1 - cos(theta)) + v.z * sin(theta);
	rot.mat[1][2] = v.z * v.y * (1 - cos(theta)) - v.x * sin(theta);
	rot.mat[2][0] = v.x * v.z * (1 - cos(theta)) - v.y * sin(theta);
	rot.mat[2][1] = v.z * v.y * (1 - cos(theta)) + v.x * sin(theta);
	return (rot);
}
