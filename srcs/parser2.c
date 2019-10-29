/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 15:19:39 by qbragard          #+#    #+#             */
/*   Updated: 2019/09/16 16:22:16 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		get_all_points(t_coord *co, char *line)
{
	int i;

	i = -1;
	while (++i < co->len)
	{
		co->color[i] = 0;
		co->tab[i] = ft_atoi_advanced_fdf(&line, co, i);
		co->original_tab[i] = co->tab[i];
	}
}

t_coord		*coord_init(int fd)
{
	char	*line;
	char	*tmp;
	t_coord	*co;

	if (!get_next_line(fd, &line) && !line)
		return (NULL);
	tmp = line;
	if (!(co = (t_coord *)malloc(sizeof(t_coord))))
		return (NULL);
	co->len = coord_counter(line);
	if (!(co->tab = (float *)malloc(sizeof(float) * (co->len))))
		return (NULL);
	if (!(co->original_tab = (float *)malloc(sizeof(float) * (co->len))))
		return (NULL);
	if (!(co->color = (int *)malloc(sizeof(int) * (co->len))))
		return (NULL);
	get_all_points(co, line);
	co->y = 0;
	co->next = NULL;
	free(tmp);
	return (co);
}

void		create_y(int y, t_coord *new, char *line)
{
	int	i;

	i = -1;
	while (++i < new->len)
	{
		new->color[i] = 0;
		new->tab[i] = ft_atoi_advanced_fdf(&line, new, i);
		new->original_tab[i] = new->tab[i];
	}
	new->y = y;
	new->next = NULL;
}

int			list_init(t_coord *new)
{
	if (!(new->tab = (float *)malloc(sizeof(float) * (new->len))))
		return (-1);
	if (!(new->original_tab = (float *)malloc(sizeof(float) * (new->len))))
		return (-1);
	if (!(new->color = (int *)malloc(sizeof(int) * (new->len))))
		return (-1);
	return (0);
}

int			next_y(t_coord **co, int fd, int y, int len)
{
	t_coord	*new;
	t_coord	*tmp;
	char	*line;
	char	*tmp_l;
	int		gnl;

	if (!(gnl = get_next_line(fd, &line)) && !line)
		return (-1);
	tmp_l = line;
	if (!(new = (t_coord *)malloc(sizeof(t_coord))))
		return (-1);
	tmp = *co;
	while (tmp->next)
		tmp = tmp->next;
	new->len = coord_counter(line);
	if (new->len != len)
		return (-2);
	if (list_init(new))
		return (-1);
	create_y(y, new, line);
	tmp->next = new;
	free(tmp_l);
	return (gnl);
}
