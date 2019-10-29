/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 15:24:58 by qbragard          #+#    #+#             */
/*   Updated: 2019/09/17 09:38:49 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define HEIGHT 1000
# define WIDTH 1000
# include <mlx.h>
# include <stdio.h>
# include "libft.h"
# include <math.h>
# include <fcntl.h>

typedef struct		s_img
{
	void			*img_ptr;
	int				*data;
	int				size_l;
	int				bpp;
	int				endian;
}					t_img;

typedef struct		s_env
{
	void			*mlx_ptr;
	void			*win_ptr;
	struct s_img	img;
	struct s_coord	*co;
	int				left;
	int				right;
	int				up;
	int				down;
	int				viz;
	int				color;
	int				red;
	int				blue;
	int				zoom;
	int				altitude;
}					t_env;

typedef struct		s_coord
{
	int				len;
	float			y;
	float			*tab;
	float			*original_tab;
	int				*color;
	float			*abs;
	float			*ord;
	float			point_space;
	struct s_coord	*next;
}					t_coord;

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_line
{
	int				v;
	int				color;
	float			dx;
	float			dy;
	float			m;
	float			e;
	t_point			a;
	t_point			b;
}					t_line;

int					coord_counter(char *line);
t_coord				*coord_init(int fd);
int					next_y(t_coord **co, int fd, int y, int len);
t_coord				*get_coord(int fd);
t_coord				*coordinates(int ac, char **av);
void				line1(t_line line, t_env env, int color);
void				line1_bis(t_line line, t_env env, int color);
void				line2(t_line line, t_env env, int color);
void				line2_bis(t_line line, t_env env, int color);
void				line3(t_line line, t_env env, int color);
void				line3_bis(t_line line, t_env env, int color);
void				line4(t_line line, t_env env, int color);
void				line4_bis(t_line line, t_env env, int color);
void				bresenham(t_line line, t_env env, int color);
void				draw_line_of_points(t_env env);
void				draw_all_points(t_env env);
t_line				create_line(t_point a, t_point b);
void				draw_line_of_coord(t_env env);
int					count_lines(t_coord *co);
int					fill_three_dimensions_coord(t_env env);
float				find_space_between_lines(t_coord *co);
float				find_space_between_points(t_coord *co);
float				find_min_ord(t_coord *co);
float				find_min_abs(t_coord *co);
void				readjust_place(t_env env);
long long			ft_atoi_advanced_fdf(char **str, t_coord *co, int j);
void				print_coord(t_coord *co);
void				create_image(t_env *env);
void				print_abs_ord(t_coord *co);
int					deal_key(int keycode, void *param);
int					ft_end(t_env *env);
void				color_recon(char **str, t_coord *co, int j);
int					ft_color(t_env *env, int keycode);
void				higher_coord(t_env *env);
void				lower_coord(t_env *env);
int					free_env_end(t_env *env);
int					free_env_not_end(t_env *env);
int					is_there_neg_coord(t_coord *co);
void				return_to_original_altitude(t_env *env);
void				saturation_coord(t_env *env);
#endif
