/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 15:47:43 by qbragard          #+#    #+#             */
/*   Updated: 2019/05/28 10:13:06 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list_gnl	*ft_new_fd(int fd, t_list_gnl **list)
{
	t_list_gnl	*new;
	t_list_gnl	*begin;

	if (*list)
	{
		begin = *list;
		while (begin->next)
		{
			if (fd == begin->file_des)
				return (begin);
			begin = begin->next;
		}
		if (begin->file_des == fd)
			return (begin);
	}
	if (!(new = (t_list_gnl*)malloc(sizeof(t_list_gnl))))
		return (NULL);
	new->content = NULL;
	new->next = NULL;
	new->file_des = fd;
	if ((*list))
		new->next = (*list);
	(*list) = new;
	return (new);
}

char		*cut_line(char *text)
{
	char	*ret;
	int		i;

	if (!(text))
		return (NULL);
	i = 0;
	if (*text == '\n')
		return (ft_strdup(""));
	while (text[i] != '\0' && text[i] != '\n')
		i++;
	if (i == 0)
		return (NULL);
	if (!(ret = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	ret = ft_memcpy(ret, text, i);
	ret[i] = '\0';
	return (ret);
}

int			read_line(int fd, t_list_gnl *list, char **line)
{
	char	buf[BUFF_SIZE + 1];
	char	*end;
	char	*tmp;
	int		rd;

	end = NULL;
	while ((rd = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[rd] = '\0';
		tmp = *line;
		*line = ft_strjoin((*line == NULL ? "" : *line), buf);
		free(tmp);
		if ((end = ft_strchr(*line, '\n')))
			break ;
	}
	if (end)
	{
		free(list->content);
		if (!(list->content = ft_strdup(end + 1)))
			return (-1);
	}
	tmp = *line;
	*line = cut_line(*line);
	free(tmp);
	return (rd);
}

void		ft_free_content(t_list_gnl *list)
{
	free(list->content);
	list->content = NULL;
}

int			get_next_line(const int fd, char **line)
{
	static t_list_gnl	*list;
	t_list_gnl			*tmp;
	char				*save;
	char				*save2;

	if (!line || fd < 0 || read(fd, NULL, 0) == -1)
		return (-1);
	*line = NULL;
	tmp = ft_new_fd(fd, &list);
	if (tmp->content)
	{
		*line = cut_line(tmp->content);
		if ((save = ft_strchr(tmp->content, '\n')))
		{
			save2 = tmp->content;
			tmp->content = ft_strlen(save) >= 1 ? ft_strdup(save + 1)
				: NULL;
			free(save2);
			return (1);
		}
		else
			ft_free_content(tmp);
	}
	return (return_gnl(fd, tmp, list, line));
}
