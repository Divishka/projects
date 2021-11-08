#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str_r;
	size_t			l;

	if (!s)
		return (NULL);
	i = 0;
	l = ft_strlen(s);
	str_r = (char *)malloc(sizeof(*s) * l + 1);
	if (!str_r)
		return (NULL);
	while (s[i])
	{
		str_r[i] = f(i, s[i]);
		i++;
	}
	str_r[i] = '\0';
	return (str_r);
}
