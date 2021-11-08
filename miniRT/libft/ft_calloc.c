/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awhana <awhana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 15:43:01 by awhana            #+#    #+#             */
/*   Updated: 2021/04/20 14:40:41 by awhana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void			*darr;
	unsigned int	n;

	n = num * size;
	darr = malloc(n);
	if (!darr)
		return (NULL);
	if (darr)
		ft_memset(darr, 0, n);
	return (darr);
}
