/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awhana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 13:37:40 by awhana            #+#    #+#             */
/*   Updated: 2021/04/17 17:20:00 by awhana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void*))
{
	t_list	*temp;

	if (lst != NULL)
	{
		temp = lst;
		while (1)
		{
			(*f)(temp->content);
			temp = temp->next;
			if (temp == NULL)
				return ;
		}
	}
}
