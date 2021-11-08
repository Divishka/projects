/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awhana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 07:31:12 by awhana            #+#    #+#             */
/*   Updated: 2021/04/18 16:35:38 by awhana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*r;
	int				i;

	i = 0;
	r = (unsigned char *)b;
	while (len > 0)
	{
		r[i] = c;
		i++;
		len--;
	}
	return (b);
}
