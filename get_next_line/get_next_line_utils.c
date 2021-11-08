/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awhana <awhana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 10:49:23 by awhana            #+#    #+#             */
/*   Updated: 2021/04/26 10:05:51 by awhana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*new;
	int				i;
	int				p;

	i = 0;
	p = 0;
	if (!s1)
		return (0);
	new = malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	if (!new)
		return (0);
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[p] != '\0')
	{
		new[i] = s2[p];
		i++;
		p++;
	}
	new[i] = '\0';
	free((char *)s1);
	return (new);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	a;

	a = (unsigned char)c;
	if (a == 0)
	{
		while (*s != '\0')
			s++;
		return ((char *)s);
	}
	while (*s != '\0')
	{
		if (*s == a)
			return ((char *)s);
		s++;
	}
	return (0);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	char	*src;
	size_t	len;

	src = (char *)s1;
	len = ft_strlen(src) + 1;
	s2 = (char *)malloc(len);
	if (s2 == 0)
		return (0);
	ft_memcpy(s2, s1, len);
	return (s2);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (n == 0 || dst == src)
		return (dst);
	while (n > 0)
	{
		*d = *s;
		d++;
		s++;
		n--;
	}
	return (dst);
}

int	ft_strlen(char *str)
{
	int				i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
