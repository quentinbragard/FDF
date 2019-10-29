/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord_modif.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 13:34:20 by qbragard          #+#    #+#             */
/*   Updated: 2019/08/06 15:41:26 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	find_space_between_lines(t_coord *co)
{
	int		i;
	t_coord	*tmp;

	i = 1;
	tmp = co;
	while (co->next)
	{
		co = co->next;
		i++;
	}
	co = tmp;
	return ((float)HEIGHT / 2 / i);
}

float	find_space_between_points(t_coord *co)
{
	float	max;
	t_coord	*tmp;

	tmp = co;
	max = (float)co->len;
	while (co)
	{
		if ((float)co->len > max)
			max = (float)co->len;
		co = co->next;
	}
	co = tmp;
	max = max > find_space_between_lines(co) ? max
		: find_space_between_lines(co);
	return (WIDTH / 2 / max);
}

float	find_min_ord(t_coord *co)
{
	t_coord	*tmp;
	float	min;
	int		i;

	tmp = co;
	min = co->ord[0];
	while (tmp && (i = -1))
	{
		while (++i < tmp->len)
			if (tmp->ord[i] < min)
				min = tmp->ord[i];
		tmp = tmp->next;
	}
	return (min);
}

float	find_min_abs(t_coord *co)
{
	t_coord	*tmp;
	float	min;
	int		i;

	tmp = co;
	min = co->abs[0];
	while (tmp && (i = -1))
	{
		while (++i < tmp->len)
			if (tmp->abs[i] < min)
				min = tmp->abs[i];
		tmp = tmp->next;
	}
	return (min);
}

void	readjust_place(t_env env)
{
	t_coord	*tmp;
	int		i;
	float	min_a;
	float	min_o;

	tmp = env.co;
	min_a = find_min_abs(env.co);
	min_o = find_min_ord(env.co);
	while (env.co && (i = -1))
	{
		while (++i < tmp->len)
		{
			env.co->abs[i] = env.co->abs[i] + 10 - min_a + env.right
				- env.left;
			env.co->ord[i] = env.co->ord[i] + 10 - min_o + env.down - env.up;
		}
		env.co = env.co->next;
	}
	env.co = tmp;
}
