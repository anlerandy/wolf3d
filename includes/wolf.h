/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 14:57:54 by alerandy          #+#    #+#             */
/*   Updated: 2018/02/15 01:51:50 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "key_codes_macos.h"
# include "get_next_line.h"
# include <pthread.h>
# include "mlx.h"
# include <math.h>

# define WIN "WolfEngine 0.01"
# define BLUR 0xF0000000
# define BLACK 0x00000000
# define BLUE 0x000000ff
# define WHITE 0x00ffffff
# define YELLOW 0x00ffff00
# define RED 0x00ff0000
# define THREADS 32

typedef struct	s_coor
{
	double		x;
	double		y;
	double		z;
}				t_coor;

typedef struct	s_frame
{
	void		*pimg;
	char		*img;
	int			bpp;
	int			s_l;
	int			ndia;
}				t_frame;

typedef struct	s_data
{
	void		*mlx;
	void		*win;
	int			win_h;
	int			win_w;
	int			flag;
	int			flag2;
	int			flag3;
	int			debug;
	int			loading;
	t_frame		frame;
	int			part;
}				t_data;

void			debug(int debug, char *str);
void			usage(int err);
char			*ft_intset(char *tab, int i, int size);

int				press(int key, void *param);
int				release(int key, void *param);

int				help();

#endif
