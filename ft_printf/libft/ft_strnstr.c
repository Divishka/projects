/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awhana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 15:25:59 by awhana            #+#    #+#             */
/*   Updated: 2021/04/18 16:41:24 by awhana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	while (big[i] && (k < n))
	{
		while ((big[i + k] == little[k]) && little[k] && ((i + k) < n))
			k++;
		if (!little[k])
			return ((char *)&big[i]);
		k = 0;
		i++;
	}
	if (!little[0])
		return ((char *)&big[i]);
	return (NULL);
}
