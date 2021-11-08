#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*r;
	int				i;

	i = 0;
	r = (unsigned char *)b;
	while (len > 0)
	{
		r[i] = c;
		i++;
		len--;
	}
	return (b);
}
