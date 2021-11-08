#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	int	i;
	int	k;

	i = ft_strlen(str);
	k = 0;
	while (i >= k)
	{
		if (str[i - k] == ch)
			return ((char *)&str[i - k]);
		k++;
	}
	return (NULL);
}
