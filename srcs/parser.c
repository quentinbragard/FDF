/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 13:35:12 by qbragard          #+#    #+#             */
/*   Updated: 2019/08/06 15:43:44 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

long long	ft_atoi_advanced_fdf(char **str, t_coord *co, int j)
{
	int			u;
	long long	result;
	int			i;

	u = 1;
	result = 0;
	i = -1;
	while (**str == ' ' || **str == '\f' || **str == '\n' || **str
			== '\r' || **str == '\t' || **str == '\v')
		(*str)++;
	if ((**str == '+') || (**str == '-'))
	{
		if (**str == '-')
			u = -1;
		(*str)++;
	}
	while (**str > 47 && **str < 58)
	{
		result = result * 10 + (**str - 48);
		(*str)++;
	}
	while (**str && **str != ' ' && **str != ',')
		(*str)++;
	color_recon(str, co, j);
	return (u * result);
}

int			coord_counter(char *line)
{
	int	count;

	count = 1;
	while (*line && *line == ' ')
		line++;
	if (!*line)
		return (0);
	while (*line)
	{
		while (*line && *line != ' ')
			line++;
		while (*line && *line == ' ')
			line++;
		if (!*line)
			return (count);
		count++;
	}
	return (count);
}
