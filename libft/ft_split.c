/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awhana <awhana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 07:19:15 by awhana            #+#    #+#             */
/*   Updated: 2021/04/20 18:05:14 by awhana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int 	words(char const *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			count++;
		i++;
	}
	count++;
	return (count);
}

static char	*allocate(char const *s, char c)
{
	char	*w;
	int		i;

	i = 0;
	while (s[i] && (s[i] != c))
		i++;
	w = (char *)malloc(sizeof(char) * (i + 1));
	if (!w)
		return (NULL);
	i = 0;
	while (s[i] && (s[i] != c))
	{
		w[i] = s[i];
		i++;
	}
	w[i] = '\0';
	return (w);
}

static char	**free_splitted(char **splitted_to_free)
{
	int		i;

	i = 0;
	while (splitted_to_free[i])
	{
		free(splitted_to_free[i]);
		i++;
	}
	free(splitted_to_free);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**splitted;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	splitted = (char **)malloc(sizeof(char *) * (words(s, c) + 1) + 1);
	if (!splitted)
		return (NULL);
	while (*s)
	{
		while (*s && (*s == c))
			s++;
		if (*s && (*s != c))
		{
			splitted[i] = allocate(s, c);
			if (!splitted[i])
				return (free_splitted(splitted));
			i++;
			while (*s && (*s != c))
				s++;
		}
	}
	splitted[i] = NULL;
	return (splitted);
}
