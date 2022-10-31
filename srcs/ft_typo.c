/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 20:41:47 by alerandy          #+#    #+#             */
/*   Updated: 2022/10/31 15:41:46 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void	draw_type(t_data *data, char c, int x, int y)
{
	static t_xpm	font;
	static int		s = 0;
	int				i;
	int				j;
	int				b;

	j = -1;
	if (!s)
		font = xpm_create(data, "xpm/typo01.xpm", 550, 550);
	s = 1;
	while (++j < 55)
	{
		i = -1;
		while (++i < 55)
		{
			b = (((c - 31) % 10) * 55 + i) + ((((c - 31) / 10) * 55) + j) * 550;
			if ((unsigned int)font.img[b] != 0xff00ffff && \
					(unsigned int)font.img[b] != 0xFF000000)
				((int*)(data->frame.img))[x + i + ((y + j) * data->win_w)] =
					font.img[b];
		}
	}
}

void		ft_type(t_data *data, char *str, int x, int y)
{
	int		i;

	i = 0;
	while (str[i])
	{
		str[i] < 32 || str[i] > 126 ? (str[i] = '}') : str[i];
		draw_type(data, str[i], x + (i * 40), y);
		i++;
	}
}
