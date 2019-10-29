/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:29:31 by qbragard          #+#    #+#             */
/*   Updated: 2019/08/06 15:41:57 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_color(t_coord *co, int j, char **str)
{
	int		i;
	char	ret[6];

	(*str)++;
	if (**str && **str != '0')
		return ;
	(*str)++;
	if (**str && **str != 'x' && **str != 'X')
		return ;
	(*str)++;
	i = 0;
	while ((*str)[i] != ' ')
		i++;
	if (i != 6)
		return ;
	i = -1;
	while (++i < 6)
	{
		ret[i] = *((*str)++);
	}
	ret[i] = '\0';
	co->color[j] = ft_atoi_base(ret, 16);
	return ;
}

void	color_recon(char **str, t_coord *co, int j)
{
	if (**str == ',')
		get_color(co, j, str);
}

void	ft_red(t_env *env)
{
	if (env->red)
	{
		env->red = 0;
		env->blue = 0;
		env->color = 0xFFFFFF;
	}
	else
	{
		env->red = 1;
		env->blue = 0;
		env->color = 0xFF0000;
	}
}

void	ft_blue(t_env *env)
{
	if (env->blue)
	{
		env->blue = 0;
		env->red = 0;
		env->color = 0xFFFFFF;
	}
	else
	{
		env->blue = 1;
		env->red = 0;
		env->color = 0x0000FF;
	}
}

int		ft_color(t_env *env, int keycode)
{
	if (keycode == 15)
		ft_red(env);
	if (keycode == 11)
		ft_blue(env);
	free_env_not_end(env);
	mlx_destroy_image(env->mlx_ptr, env->img.img_ptr);
	create_image(env);
	fill_three_dimensions_coord(*env);
	draw_all_points(*env);
	return (0);
}
