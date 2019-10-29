/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord_modif2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 13:56:30 by qbragard          #+#    #+#             */
/*   Updated: 2019/09/16 16:21:00 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	coord_multiplication(int i, float *ab, float *or, t_env env)
{
	if (!(env.viz % 2))
	{
		ab[i] = i * 0.9 * (env.co->point_space + env.zoom)
			- (env.co->y * 0.9 * (env.co->point_space + env.zoom));
		or[i] = -env.co->tab[i] * (env.co->point_space + env.zoom)
			+ (i * 0.45 * (env.co->point_space + env.zoom))
			+ (env.co->y * 0.45 * (env.co->point_space + env.zoom));
	}
	else
	{
		ab[i] = (i + 0.9 * env.co->tab[i]) * (env.co->point_space + env.zoom);
		or[i] = (env.co->y + 0.45 * env.co->tab[i]) * (env.co->point_space
				+ env.zoom);
	}
}

int		fill_three_dimensions_coord(t_env env)
{
	t_coord	*tmp;
	float	*abscisse;
	float	*ordonne;
	int		i;

	tmp = env.co;
	while (env.co)
	{
		i = -1;
		if (!(abscisse = (float *)malloc(sizeof(float) * env.co->len)))
			return (-1);
		if (!(ordonne = (float *)malloc(sizeof(float) * env.co->len)))
			return (-1);
		while (++i < env.co->len)
			coord_multiplication(i, abscisse, ordonne, env);
		env.co->abs = abscisse;
		env.co->ord = ordonne;
		env.co = env.co->next;
	}
	env.co = tmp;
	readjust_place(env);
	if (is_there_neg_coord(env.co))
		saturation_coord(&env);
	return (0);
}

void	return_to_original_altitude(t_env *env)
{
	t_coord	*tmp;
	int		i;

	tmp = env->co;
	while (env->co && (i = -1))
	{
		while (++i < env->co->len)
			env->co->tab[i] = env->co->original_tab[i];
		env->co = env->co->next;
	}
	env->co = tmp;
	env->altitude = 0;
}
