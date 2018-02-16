/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 14:57:54 by alerandy          #+#    #+#             */
/*   Updated: 2018/02/16 07:30:11 by acourtin         ###   ########.fr       */
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
# define FADE 2

typedef struct		s_coor
{
	double			x;
	double			y;
	double			z;
}					t_coor;

typedef struct		s_intro_list
{
	int				launched;
	int				qd;
	int				auth;
	int				fin;
}					t_intro;

typedef struct		s_frame
{
	void			*pimg;
	char			*img;
	int				bpp;
	int				s_l;
	int				ndia;
}					t_frame;

typedef struct		s_xpm
{
	void			*pimg;
	int				*img;
	int				width;
	int				height;
	int				bpp;
	int				s_l;
	int				ndia;
}					t_xpm;

typedef struct		s_menu
{
	int				selection;
}					t_menu;

typedef enum		e_game_state
{
	MENU,
	GAME
}					t_game_state;

typedef struct		s_data
{
	void			*mlx;
	void			*win;
	int				win_h;
	int				win_w;
	int				flag;
	int				flag2;
	int				flag3;
	int				debug;
	int				loading;
	t_frame			frame;
	t_frame			fade;
	t_frame			tmp;
	int				fade_c;
	int				part;
	t_intro			intro;
	t_menu			menu;
	t_game_state	game_state;
}					t_data;

void				debug(int debug, char *str);
void				usage(int err);
int					wolf_exit(void);

char				*ft_intset(char *tab, int i, int size);
char				*ft_intadd(char *tab, int i, int size);
int					fade_to(void *param);

int					press(int key, void *param);
int					release(int key, void *param);
int					help();

t_xpm				xpm_create(t_data *data, char *xpmname, int w, int h);
void				xpm_draw(t_data *data, t_xpm xpm, int x, int y);
void				tmp_draw_f(t_data *data);

void				init_menu(t_data *data);
void				draw_menu(t_data *data);
void				execute_menu(t_data *data);
void				skip_to_menu(t_data *data);

#endif
