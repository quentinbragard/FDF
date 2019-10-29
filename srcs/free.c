/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 11:56:27 by qbragard          #+#    #+#             */
/*   Updated: 2019/09/16 11:56:28 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		free_env_end(t_env *env)
{
	t_coord *tmp;

	tmp = env->co;
	while (tmp)
	{
		free(tmp->tab);
		free(tmp->original_tab);
		free(tmp->abs);
		free(tmp->ord);
		free(tmp->color);
		env->co = tmp;
		tmp = tmp->next;
		free(env->co);
	}
	return (1);
}

int		free_env_not_end(t_env *env)
{
	t_coord *tmp;

	tmp = env->co;
	while (tmp)
	{
		free(tmp->abs);
		free(tmp->ord);
		tmp = tmp->next;
	}
	return (1);
}
