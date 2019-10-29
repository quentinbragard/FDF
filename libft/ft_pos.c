/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzimmerm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 18:04:39 by lzimmerm          #+#    #+#             */
/*   Updated: 2019/07/22 18:04:45 by lzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_pos(char c, char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == c)
			return (i + 1);
		i++;
		str++;
	}
	return (0);
}