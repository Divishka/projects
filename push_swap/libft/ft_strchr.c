#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	int	i;

	i = 0;
	while (str[i] != ch)
	{
		if (!str[i])
			return (NULL);
		i++;
	}
	return ((char *)&str[i]);
}
