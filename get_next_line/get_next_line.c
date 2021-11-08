/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awhana <awhana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 10:46:25 by awhana            #+#    #+#             */
/*   Updated: 2021/04/26 11:43:27 by awhana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

typedef struct s_args
{
	int	fd;
	int	byte_was_read;
}			t_args;

int	error_free(char *remains, char *buf, int i)
{
	if (remains != NULL)
		free(remains);
	if (buf != NULL)
		free(buf);
	return (i);
}

int	search_for_n(char **remains, char **line)
{
	char		*pointer;
	char		*temp;

	temp = *remains;
	pointer = ft_strchr(*remains, '\n');
	if (pointer)
	{
		*pointer = '\0';
		*line = ft_strdup(*remains);
		if (!(*line))
		{
			free(remains);
			return (-1);
		}
		*remains = ft_strdup(++pointer);
		if (!(*remains))
		{
			free(remains);
			return (-1);
		}
		free(temp);
		return (1);
	}
	return (0);
}

int	parse(t_args p, char **remains, char **line, char *buf)
{
	while (p.byte_was_read)
	{
		buf[p.byte_was_read] = '\0';
		*remains = ft_strjoin(*remains, buf);
		if (!*remains)
			return (error_free(*remains, buf, -1));
		if (search_for_n(&(*remains), line) == 1)
			return (error_free(NULL, buf, 1));
		else if (search_for_n(&(*remains), line) == -1)
			return (-1);
		p.byte_was_read = read(p.fd, buf, BUFFER_SIZE);
	}
	free(buf);
	if (search_for_n(&(*remains), line) == 1)
		return (1);
	*line = ft_strdup(*remains);
	if (!(*line))
		return (error_free(*remains, buf, -1));
	free(*remains);
	*remains = NULL;
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char		*buf;
	int			i;
	static char	*remains;
	t_args		p;

	if (BUFFER_SIZE < 1 || !line || fd < 0 || (read(fd, 0, 0) < 0))
		return (-1);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (-1);
	if (!remains)
		remains = ft_strdup("");
	p.byte_was_read = read(fd, buf, BUFFER_SIZE);
	p.fd = fd;
	i = parse(p, &remains, line, buf);
	return (i);
}
