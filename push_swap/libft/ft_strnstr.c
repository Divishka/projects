#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	while (big[i] && (k < n))
	{
		while ((big[i + k] == little[k]) && little[k] && ((i + k) < n))
			k++;
		if (!little[k])
			return ((char *)&big[i]);
		k = 0;
		i++;
	}
	if (!little[0])
		return ((char *)&big[i]);
	return (NULL);
}
