/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awhana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 15:51:15 by awhana            #+#    #+#             */
/*   Updated: 2021/04/18 16:43:54 by awhana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *arr1, const void *arr2, size_t n)
{
	size_t			i;
	unsigned char	*ret1;
	unsigned char	*ret2;

	ret1 = (unsigned char *)arr1;
	ret2 = (unsigned char *)arr2;
	i = 0;
	while ((i < n) && (ret1[i] == ret2[i]))
		i++;
	if (i == n)
		return (0);
	else
		return (ret1[i] - ret2[i]);
}
