/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awhana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 12:36:28 by awhana            #+#    #+#             */
/*   Updated: 2021/04/18 18:37:44 by awhana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_;

	new_ = (t_list *)malloc(sizeof(t_list));
	if (!new_)
		return (NULL);
	new_->content = content;
	new_->next = NULL;
	return (new_);
}
