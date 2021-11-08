#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;
	t_list	*element;

	temp = *lst;
	while (temp)
	{
		element = temp->next;
		del(temp->content);
		free(temp);
		temp = element;
	}
	*lst = NULL;
}
