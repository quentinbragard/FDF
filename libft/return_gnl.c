/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_gnl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 10:07:46 by qbragard          #+#    #+#             */
/*   Updated: 2019/05/29 15:50:10 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		return_gnl(int fd, t_list_gnl *tmp, t_list_gnl *list, char **line)
{
	int rd;

	rd = read_line(fd, tmp, line);
	if (!*line)
		free(list);
	rd = (rd == 0) ? 2 : 1;
	return (*line ? rd : 0);
}
