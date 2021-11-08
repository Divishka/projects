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
