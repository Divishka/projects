/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awhana <awhana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 11:19:01 by awhana            #+#    #+#             */
/*   Updated: 2021/04/29 11:13:18 by awhana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	length_str(long int n)
{
	long int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < len)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(long int num)
{
	long int	i;
	long int	n;
	char		*s;

	i = 0;
	n = length_str(num);
	s = (char *)malloc(sizeof(char) * (n + 1));
	if (!s)
		return (NULL);
	s[n] = '\0';
	if (num < 0)
	{
		s[0] = '-';
		num = num * -1;
		i++;
	}
	while (i < n--)
	{
		s[n] = (num % 10) + '0';
		num = num / 10;
	}
	return (s);
}
