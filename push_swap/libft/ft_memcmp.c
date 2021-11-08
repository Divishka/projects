#include "libft.h"

int	ft_memcmp(const void *arr1, const void *arr2, size_t n)
{
	size_t			i;
	unsigned char	*ret1;
	unsigned char	*ret2;

	ret1 = (unsigned char *)arr1;
	ret2 = (unsigned char *)arr2;
	i = 0;
	while ((i < n) && (ret1[i] == ret2[i]))
		i++;
	if (i == n)
		return (0);
	else
		return (ret1[i] - ret2[i]);
}
