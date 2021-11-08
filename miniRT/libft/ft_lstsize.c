/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awhana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 12:47:25 by awhana            #+#    #+#             */
/*   Updated: 2021/04/18 08:49:09 by awhana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*temp;

	count = 0;
	temp = lst;
	if (lst == NULL)
		return (0);
	while (temp->next != NULL)
	{
		count++;
		temp = temp->next;
	}
	if (temp->next == NULL)
		count++;
	return (count);
}
