/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaronda <elaronda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 18:08:50 by elaronda          #+#    #+#             */
/*   Updated: 2021/01/28 02:28:14 by elaronda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>

# define FORWARD 13
# define BACK 1
# define LEFT 0
# define RIGHT 2
# define ROTATE_LEFT 123
# define ROTATE_RIGHT 124
# define ESC 53

typedef	struct	s_check {
	int			r;
	int			so;
	int			we;
	int			ea;
	int			no;
	int			s;
	int			c;
	int			f;
	int			done;
}				t_check;

typedef	struct	s_info {
	int			*size;
	int			*center;
	int			*x;
	int			*y;
	double		*sp_len;
	double		*luchi_array;
}				t_info;

typedef	struct	s_data {
	void		*img;
	void		*mlx;
	void		*mlx_win;
	char		*addr;
	int			tex_width;
	int			tex_height;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	char		*path;
}				t_data;

typedef	struct	s_sprite {
	int			start;
	int			end;
	int			left;
	int			right;
	int			fact_width;
	int			act_width;
	double		h_iter;
	double		w_iter;
}				t_sprite;

typedef	struct	s_tex {
	int			floor_color;
	int			ceiling_color;
	t_data		s;
	t_data		w;
	t_data		e;
	t_data		n;
	t_data		sprite;
}				t_tex;

typedef	struct	s_ray {
	double		pdx;
	double		pdy;
	double		pa;
	double		px;
	double		py;
	double		x;
	double		y;
	int			no_clip;
}				t_ray;

typedef	struct	s_all {
	int			width;
	int			height;
	int			side;
	char		**map;
	int			scale;
	int			minimap_flag;
	int			longer_string;
	int			upd;
	int			cnt;
	t_sprite	sprite;
	t_ray		ray;
	t_data		win;
	t_tex		tex;
	t_info		info;
	t_check		check;
}				t_all;

int				get_next_line(int fd, char **line);
void			init_arrays(t_all *all);
void			init_struct(t_all *all);
void			init_checker(t_all *all);
void			draw(t_all *all);
void			draw_floor(t_all *all);
void			draw_3d(t_all *all, int wall, int luchi, double k);
void			refresh_vars(t_all *all);
void			sort(t_all *all, int cnt);
void			draw_sprite(t_all *all, int q);
int				valid_keys(char c, char d);
int				create_screen(t_all *all);
void			open_map(t_all *all, char *file_name);
void			player_detect(t_all *all, int lines, int i);
void			map_hole_check(t_all *all, int line_max);
void			c_color_parser(t_all *all, char *s);
void			f_color_parser(t_all *all, char *s);
void			sprite_parser(t_all *all, char *s, int code);
void			tex_parser(t_all *all, char *s, int code);
void			tex_parser2(t_all *all, char *s, int code);
void			resolution_parser(t_all *all, char *s);
void			init_map_to_buffer(t_all *all);
int				key_hook(int keycode, t_all *all);
int				check_side2(t_all *all, int quarter);
int				check_side(t_all *all);
void			isdone(t_all *all);
int				no_clip(t_all *all, int a);
void			no_clip2(t_all *all, int a, double *temppx, double *temppy);
int				check_cub_extension(char *s, int av);
int				check_xpm_extension(char *s);
int				access_symbols(char c);
void			new_image(t_all *all);
void			pxl(t_data *win, int x, int y, int color);
int				get_color(t_data *polar, int x, int y);
double			fix_ang(double f);
int				rgb_to_hex(int r, int g, int b);
size_t			ft_strlen(char *str);
char			*ft_strdup(const char *str);
int				ft_atoi(const char *str);
int				ft_isdigit(int ch);
void			ft_bzero(void *s, size_t n);
void			ft_error(int code);
void			error_check(t_all *all);

#endif
