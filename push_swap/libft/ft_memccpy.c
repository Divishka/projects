#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	i = 0;
	if (!dst && !src)
		return (dst);
	while (n > 0)
	{
		d[i] = s[i];
		if (s[i] == (unsigned char)c)
			return (dst + i + 1);
		i++;
		n--;
	}
	return (NULL);
}
