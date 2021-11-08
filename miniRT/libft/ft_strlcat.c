/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awhana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 16:26:38 by awhana            #+#    #+#             */
/*   Updated: 2021/04/16 16:48:12 by awhana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	while (dst[i] && i < size)
		i++;
	while (src[k] && (i + k + 1) < size)
	{
		dst[i + k] = src[k];
		k++;
	}
	if (i < size)
		dst[i + k] = '\0';
	return (i + ft_strlen(src));
}
