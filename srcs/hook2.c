/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:32:02 by qbragard          #+#    #+#             */
/*   Updated: 2019/09/16 16:14:42 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		is_there_neg_coord(t_coord *co)
{
	t_coord	*tmp;
	int		i;

	tmp = co;
	while (tmp && (i = -1))
	{
		while (++i < tmp->len)
			if (tmp->abs[i] < 0 || tmp->ord[i] < 0 || tmp->abs[i] > WIDTH
					|| tmp->ord[i] > HEIGHT)
				return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	higher_coord(t_env *env)
{
	int		i;
	t_coord	*tmp;

	if (env->altitude < 10 && !is_there_neg_coord(env->co))
	{
		env->altitude++;
		tmp = env->co;
		while (env->co && (i = -1))
		{
			while (++i < env->co->len)
				env->co->tab[i] = env->co->tab[i] * 1.1;
			env->co = env->co->next;
		}
		env->co = tmp;
	}
	else
		return_to_original_altitude(env);
}

void	lower_coord(t_env *env)
{
	int		i;
	t_coord	*tmp;

	if (env->altitude > -10 && !is_there_neg_coord(env->co))
	{
		env->altitude--;
		tmp = env->co;
		while (env->co && (i = -1))
		{
			while (++i < env->co->len)
				env->co->tab[i] = env->co->tab[i] * 0.9;
			env->co = env->co->next;
		}
		env->co = tmp;
	}
	else
		return_to_original_altitude(env);
}

int		end_of_viz(t_env env)
{
	mlx_destroy_window(env.mlx_ptr, env.win_ptr);
	free_env_end(&env);
	return (0);
}

int		ft_end(t_env *env)
{
	end_of_viz(*env);
	exit(0);
	return (0);
}
