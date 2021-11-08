/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awhana <awhana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 07:11:36 by awhana            #+#    #+#             */
/*   Updated: 2021/04/20 15:36:32 by awhana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int 	ft_cis(char c, char const *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	st;
	size_t	en;

	st = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	while (s1[st] && ft_cis(s1[st], set))
		st++;
	en = ft_strlen(s1);
	while (en > st && ft_cis(s1[en - 1], set))
		en--;
	str = (char *)malloc(sizeof(*s1) * (en - st + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (st < en)
		str[i++] = s1[st++];
	str[i] = 0;
	return (str);
}
