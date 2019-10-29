/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 13:34:11 by qbragard          #+#    #+#             */
/*   Updated: 2019/08/05 13:40:33 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bresenham1(t_line line, t_env env, int color)
{
	t_point	ref;

	ref.x = line.a.x;
	ref.y = line.a.y;
	if (line.m >= 1)
		line1(line, env, color);
	else if (line.m >= 0 && line.m <= 1)
		line2(line, env, color);
	else if (line.m <= 0 && line.m >= -1)
		line3(line, env, color);
	else if (line.m <= -1)
		line4(line, env, color);
}

void	vertical(t_line line, t_env env, int color)
{
	t_point	ref;

	ref.x = line.a.x;
	ref.y = line.a.y;
	if (ref.y < line.b.y)
	{
		while (ref.y < line.b.y)
		{
			env.img.data[ref.y * WIDTH + ref.x] = color;
			ref.y++;
		}
	}
	else
	{
		while (ref.y > line.b.y)
		{
			env.img.data[ref.y * WIDTH + ref.x] = color;
			ref.y--;
		}
	}
}

void	bresenham2(t_line line, t_env env, int color)
{
	t_point	ref;

	ref.x = line.a.x;
	ref.y = line.a.y;
	if (line.v == 1)
		vertical(line, env, color);
	if (line.m <= -1)
		line1_bis(line, env, color);
	else if (line.m <= 0 && line.m >= -1)
		line2_bis(line, env, color);
	else if (line.m >= 0 && line.m <= 1)
		line3_bis(line, env, color);
	else if (line.m >= 1)
		line4_bis(line, env, color);
}

void	bresenham(t_line line, t_env env, int color)
{
	if (line.a.x < line.b.x)
		bresenham1(line, env, color);
	else
		bresenham2(line, env, color);
}
