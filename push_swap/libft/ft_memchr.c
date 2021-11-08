#include "libft.h"

void	*ft_memchr(const void *ptr, int v, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)ptr;
	while (i < n)
	{
		if (str[i] == (unsigned char)v)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}
