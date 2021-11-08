#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	if (dst == NULL && src == NULL)
		return (0);
	i = -1;
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (s < d)
		while (n-- > 0)
			d[n] = s[n];
	else
		while (++i < n)
			d[i] = s[i];
	return (dst);
}
