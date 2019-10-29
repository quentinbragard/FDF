/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixels.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 13:34:26 by qbragard          #+#    #+#             */
/*   Updated: 2019/08/06 15:43:55 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line_of_points(t_env env)
{
	int		i;

	i = -1;
	while (++i < env.co->len)
		mlx_pixel_put(env.mlx_ptr, env.win_ptr, env.co->abs[i],
				env.co->ord[i], env.co->color[i]);
}

t_line	create_line(t_point a, t_point b)
{
	t_line	line;

	line.a = a;
	line.b = b;
	line.e = 0;
	line.dx = b.x - a.x;
	line.dy = a.y - b.y;
	if (line.dx)
	{
		line.m = line.dy / line.dx;
		line.v = 0;
	}
	else
	{
		line.m = 0;
		line.v = 1;
	}
	return (line);
}

void	draw_line_of_coord(t_env env)
{
	t_line	line;
	t_point	a;
	t_point	b;
	int		i;
	int		color;

	i = -1;
	while (++i < env.co->len - 1)
	{
		a.x = env.co->abs[i];
		a.y = env.co->ord[i];
		b.x = env.co->abs[i + 1];
		b.y = env.co->ord[i + 1];
		line = create_line(a, b);
		if (env.co->color[i] != 0)
			color = env.co->color[i];
		else
			color = env.color;
		bresenham(line, env, color);
	}
}

void	draw_all_columns(t_env env)
{
	int		i;
	t_coord	*tmp[2];
	t_point	a[2];
	t_line	line;
	int		color;

	i = -1;
	tmp[0] = env.co;
	while (++i < env.co->len)
	{
		env.co = tmp[0];
		while (env.co->next)
		{
			tmp[1] = env.co->next;
			a[0].x = env.co->abs[i];
			a[0].y = env.co->ord[i];
			a[1].x = (tmp[1])->abs[i];
			a[1].y = (tmp[1])->ord[i];
			line = create_line(a[0], a[1]);
			color = env.co->color[i] != 0 ? env.co->color[i] : env.color;
			bresenham(line, env, color);
			env.co = env.co->next;
		}
	}
}

void	draw_all_points(t_env env)
{
	t_coord *tmp;

	tmp = env.co;
	while (env.co)
	{
		draw_line_of_coord(env);
		draw_line_of_points(env);
		env.co = env.co->next;
	}
	env.co = tmp;
	draw_all_columns(env);
	mlx_put_image_to_window(env.mlx_ptr, env.win_ptr, env.img.img_ptr, 0, 0);
}
