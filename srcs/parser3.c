/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 16:22:53 by qbragard          #+#    #+#             */
/*   Updated: 2019/09/16 16:27:37 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coord	*get_coord(int fd)
{
	t_coord	*co;
	t_coord	*tmp;
	int		ret;
	int		y;

	if (!(co = coord_init(fd)))
		return (NULL);
	y = 1;
	while ((ret = next_y(&co, fd, y, co->len)) == 1)
		y++;
	if (ret == -2)
		return (NULL);
	tmp = co;
	while (tmp)
	{
		tmp->point_space = find_space_between_points(co);
		tmp = tmp->next;
	}
	return (co);
}

t_coord	*coordinates(int ac, char **av)
{
	int			fd;
	t_coord		*co;

	if (ac != 2)
		return (NULL);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (NULL);
	if (!(co = get_coord(fd)))
		return (NULL);
	return (co);
}

void	saturation_coord(t_env *env)
{
	t_coord	*tmp;
	int		i;

	tmp = env->co;
	while (tmp && (i = -1))
	{
		while (++i < tmp->len)
		{
			if (tmp->abs[i] < 0)
				tmp->abs[i] = 0;
			if (tmp->ord[i] < 0)
				tmp->ord[i] = 0;
			if (tmp->abs[i] > WIDTH)
				tmp->abs[i] = WIDTH;
			if (tmp->ord[i] > HEIGHT)
				tmp->ord[i] = HEIGHT;
		}
		tmp = tmp->next;
	}
}
