/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awhana <awhana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 16:56:45 by awhana            #+#    #+#             */
/*   Updated: 2021/04/20 15:36:17 by awhana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	int	i;
	int	k;

	i = ft_strlen(str);
	k = 0;
	while (i >= k)
	{
		if (str[i - k] == ch)
			return ((char *)&str[i - k]);
		k++;
	}
	return (NULL);
}
