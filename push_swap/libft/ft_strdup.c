#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*str_r;
	size_t	i;

	i = ft_strlen(str);
	str_r = (char *)malloc(sizeof(char) * (i + 1));
	if (!str_r)
		return (NULL);
	i = 0;
	while (str[i])
	{
		str_r[i] = str[i];
		i++;
	}
	str_r[i] = '\0';
	return (str_r);
}
