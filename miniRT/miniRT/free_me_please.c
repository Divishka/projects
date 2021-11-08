/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_me_please.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awhana <awhana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 12:14:44 by awhana            #+#    #+#             */
/*   Updated: 2021/05/03 12:15:10 by awhana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

char	**free_for_split(char **split)
{
	int		i;

	i = 0;
	while (split[i])
	{
		ft_strdel(&split[i]);
		i++;
	}
	free(split);
	split = NULL;
	return (split);
}
