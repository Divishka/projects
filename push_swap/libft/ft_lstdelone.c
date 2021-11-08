#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	t_list	*temp;

	temp = lst;
	del(temp->content);
	free(lst);
}
