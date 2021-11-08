#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void			*darr;
	unsigned int	n;

	n = num * size;
	darr = malloc(n);
	if (!darr)
		return (NULL);
	if (darr)
		ft_memset(darr, 0, n);
	return (darr);
}
