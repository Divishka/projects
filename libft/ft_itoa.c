/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awhana <awhana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 11:19:01 by awhana            #+#    #+#             */
/*   Updated: 2021/04/20 14:41:30 by awhana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	length_str(int n)
{
	int	len;

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

char	*ft_itoa(int num)
{
	size_t	i;
	size_t	n;
	char	*s;

	i = 0;
	if (num == -2147483648)
		return (ft_strdup("-2147483648"));
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
