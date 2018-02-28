/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerandy <alerandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 14:57:54 by alerandy          #+#    #+#             */
/*   Updated: 2018/02/28 15:18:17 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "key_codes_macos.h"
# include "get_next_line.h"
# include <pthread.h>
# include "mlx.h"
# include "map.h"
# include "player.h"
# include <math.h>
# include <time.h>

# define WIN "WolfEngine 0.04"
# define BLUR 0xF0000000
# define BLACK 0x00000000
# define BLUE 0x000000ff
# define WHITE 0x00ffffff
# define YELLOW 0x00ffff00
# define RED 0x00ff0000
# define THREADS 32
# define FADE 1
# define DOORSPEED 30

typedef struct		s_intro_list
{
	int				launched;
	int				qd;
	int				auth;
	int				fin;
}					t_intro;

typedef struct		s_verifyfile
{
	int				fd;
	char			*line;
	int				step;
}					t_verifyfile;

typedef struct		s_frame
{
	int				width;
	int				height;
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
	GAME,
	PAUSE
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
	int				load_ani;
	t_frame			frame;
	t_frame			fade;
	t_frame			tmp;
	t_frame			minimap;
	int				fade_c;
	int				part;
	int				actual_time;
	int				last_time;
	int				fps;
	t_intro			intro;
	t_menu			menu;
	t_game_state	game_state;
	t_map			map;
	t_player		player;
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
void				xpm_draw(t_data *data, t_xpm xpm);
void				tmp_draw_f(t_data *data);
void				xpm_draw_img(t_frame *tmp, t_xpm xpm, int x, int y);
void				loading(t_data *data);
void				loading2(t_data *data);

void				init_menu(t_data *data);
void				draw_menu(t_data *data);
void				rebuild_menu(t_data *data);
void				execute_menu(t_data *data);
void				execute_pause(t_data *data);
void				skip_to_menu(t_data *data);

void				ft_type(t_data *data, char *str, int x, int y);

void				map(t_data *data, int map);
void				step_one(t_data *data, char *line, int i);
void				step_two(t_data *data, char *line, int i);
void				step_three(t_data *data, char *line, int i);

void				draw_pause(t_data *data);
void				map_clear(t_data *data);

void				init_player(t_data *data);
void				loop_player(t_data *data);
int					move_player(t_data *data, int d);
void				ft_player_input(t_data *data, int key, int pressing);
void				init_tiles(t_data *data, int *step);
void				draw_map(t_data *data);

void				draw_minimap(t_data *data);
void				draw_ath(t_data *data);
void				draw_wall(t_data *data, t_ray ray, int slice);

void				send_ray(t_data *data, t_ray *r, double rotx, double roty);
void				loop_fps(t_data *data);
int					get_actual_time(t_data *data);

void				draw_gun_mod(t_data *data, int frame);

#endif
