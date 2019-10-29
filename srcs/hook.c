/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:30:06 by qbragard          #+#    #+#             */
/*   Updated: 2019/08/06 15:30:07 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_deplace(t_env *env, int keycode)
{
	if (!is_there_neg_coord(env->co))
	{
		if (keycode == 123)
			env->left += 10;
		if (keycode == 124)
			env->right += 10;
		if (keycode == 125)
			env->down += 10;
		if (keycode == 126)
			env->up += 10;
	}
	else
	{
		env->left = 0;
		env->right = 0;
		env->up = 0;
		env->down = 0;
	}
	free_env_not_end(env);
	mlx_destroy_image(env->mlx_ptr, env->img.img_ptr);
	create_image(env);
	fill_three_dimensions_coord(*env);
	draw_all_points(*env);
	return (0);
}

int		ft_viz(t_env *env, int keycode)
{
	if (keycode == 49)
		env->viz++;
	free_env_not_end(env);
	mlx_destroy_image(env->mlx_ptr, env->img.img_ptr);
	create_image(env);
	fill_three_dimensions_coord(*env);
	draw_all_points(*env);
	return (0);
}

int		ft_zoom(t_env *env, int keycode)
{
	if (is_there_neg_coord(env->co) || env->zoom > 10 || env->zoom < -10)
		env->zoom = 0;
	else if (keycode == 69)
		env->zoom++;
	else if (keycode == 78)
		env->zoom--;
	free_env_not_end(env);
	mlx_destroy_image(env->mlx_ptr, env->img.img_ptr);
	create_image(env);
	fill_three_dimensions_coord(*env);
	draw_all_points(*env);
	return (0);
}

int		ft_alt(t_env *env, int keycode)
{
	if (keycode == 67)
		higher_coord(env);
	if (keycode == 75)
		lower_coord(env);
	free_env_not_end(env);
	mlx_destroy_image(env->mlx_ptr, env->img.img_ptr);
	create_image(env);
	fill_three_dimensions_coord(*env);
	draw_all_points(*env);
	return (0);
}

int		deal_key(int keycode, void *param)
{
	if (keycode == 53)
		ft_end((t_env*)param);
	if (keycode == 123 || keycode == 124 || keycode == 125 || keycode == 126)
		ft_deplace((t_env*)param, keycode);
	if (keycode == 67 || keycode == 75)
		ft_alt((t_env*)param, keycode);
	if (keycode == 69 || keycode == 78)
		ft_zoom((t_env*)param, keycode);
	if (keycode == 49)
		ft_viz((t_env*)param, keycode);
	if (keycode == 11 || keycode == 15 || keycode == 82)
		ft_color((t_env*)param, keycode);
	return (0);
}
