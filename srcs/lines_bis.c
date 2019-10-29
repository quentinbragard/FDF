/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines_bis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 13:34:42 by qbragard          #+#    #+#             */
/*   Updated: 2019/08/05 15:04:09 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	line1_bis(t_line line, t_env env, int color)
{
	t_point ref;

	ref.x = line.a.x;
	ref.y = line.a.y;
	while (ref.y > line.b.y)
	{
		env.img.data[ref.y * WIDTH + ref.x] = color;
		if (2 * (line.e - line.dx) < line.dy)
			line.e = line.e - line.dx;
		else
		{
			ref.x--;
			line.e = line.e - line.dx - line.dy;
		}
		ref.y--;
	}
}

void	line2_bis(t_line line, t_env env, int color)
{
	t_point ref;

	ref.x = line.a.x;
	ref.y = line.a.y;
	while (ref.x > line.b.x)
	{
		env.img.data[ref.y * WIDTH + ref.x] = color;
		if (2 * (line.e + line.dy) < line.dx)
			line.e = line.e + line.dy;
		else
		{
			ref.y--;
			line.e = line.e + line.dy + line.dx;
		}
		ref.x--;
	}
}

void	line3_bis(t_line line, t_env env, int color)
{
	t_point ref;

	ref.x = line.a.x;
	ref.y = line.a.y;
	while (ref.x > line.b.x)
	{
		env.img.data[ref.y * WIDTH + ref.x] = color;
		if (2 * (line.e - line.dy) < line.dx)
			line.e = line.e - line.dy;
		else
		{
			ref.y++;
			line.e = line.e - line.dy + line.dx;
		}
		ref.x--;
	}
}

void	line4_bis(t_line line, t_env env, int color)
{
	t_point ref;

	ref.x = line.a.x;
	ref.y = line.a.y;
	while (ref.y < line.b.y)
	{
		env.img.data[ref.y * WIDTH + ref.x] = color;
		if (2 * (line.e - line.dx) < line.dy)
			line.e = line.e - line.dx;
		else
		{
			ref.x--;
			line.e = line.e - line.dx + line.dy;
		}
		ref.y++;
	}
}
