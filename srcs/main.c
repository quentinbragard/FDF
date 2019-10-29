/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 13:34:48 by qbragard          #+#    #+#             */
/*   Updated: 2019/08/06 15:37:43 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	create_image(t_env *env)
{
	int bpp;
	int s_l;
	int endian;

	env->img.img_ptr = mlx_new_image(env->mlx_ptr, WIDTH, HEIGHT);
	env->img.data = (int*)mlx_get_data_addr(env->img.img_ptr,
			&bpp, &s_l, &endian);
}

void	env_init(t_env *env)
{
	env->up = 0;
	env->down = 0;
	env->left = 0;
	env->right = 0;
	env->viz = 0;
	env->color = 0xFFFFFF;
	env->blue = 0;
	env->red = 0;
	env->altitude = 0;
}

int		main(int ac, char **av)
{
	t_env		env;

	env_init(&env);
	if (!(env.co = coordinates(ac, av)))
		return (-1);
	if (fill_three_dimensions_coord(env))
		return (-1);
	if (!(env.mlx_ptr = mlx_init()))
		return (-1);
	if (!(env.win_ptr = mlx_new_window(env.mlx_ptr, WIDTH, HEIGHT, av[1])))
		return (-1);
	create_image(&env);
	env.img.data = (int *)mlx_get_data_addr(env.img.img_ptr,
			&env.img.bpp, &env.img.size_l, &env.img.endian);
	draw_all_points(env);
	mlx_key_hook(env.win_ptr, deal_key, &env);
	mlx_hook(env.win_ptr, 17, 0, ft_end, &env);
	mlx_loop(env.mlx_ptr);
	return (0);
}
