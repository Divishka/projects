/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awhana <awhana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 06:53:42 by awhana            #+#    #+#             */
/*   Updated: 2021/04/20 17:24:02 by awhana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str_r;
	size_t	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str_r = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str_r)
		return (NULL);
	while (*s1)
	{
		str_r[i] = *s1;
		s1++;
		i++;
	}
	while (*s2)
	{
		str_r[i] = *s2;
		i++;
		s2++;
	}
	str_r[i] = '\0';
	return (str_r);
}
