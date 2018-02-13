/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 14:57:54 by alerandy          #+#    #+#             */
/*   Updated: 2018/02/13 14:58:43 by alerandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "get_next_line.h"

# define WIN "WolfEngine 0.01  /  "
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
	char		*name;
	int			win_h;
	int			win_w;
	double		min_x;
	double		max_x;
	double		min_y;
	double		max_y;
	t_coor		center;
	double		mouse_x;
	double		mouse_y;
	int			flag;
	int			flag2;
	int			flag3;
	t_frame		frame;
	t_frame		map;
	int			part;
	int			back;
}				t_data;

typedef struct	s_env
{
	int			win_h;
	int			win_w;
	double		zoom;
	int			part;
	double		mouse_x;
	double		mouse_y;
	t_coor		delta;
	double		min_y;
	double		min_x;
	t_frame		*frame;
	int			iter;
	int			col;
	double		pow;
	int			flag3;
}				t_env;

void			ft_tabdel(void *tab, int len);
void			ft_memclr(void *ap, size_t len);
void			usage(int err);
int				ft_close(void);

int				second(char *av);
t_env			set_env(t_data *data);

int				help();

#endif
