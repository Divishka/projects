#include "libft.h"
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	size_t			ml;
	char			*out;

	if (!s || len <= 0 || start >= ft_strlen(s))
		return (ft_strdup(""));
	else
	{
		ml = ft_strlen(&s[start]);
		if (ml < len)
			len = ml;
		out = (char *)malloc((len + 1) * sizeof(char));
		if (!out)
			return (NULL);
		i = start;
		while (s[i] && (i - start) < len)
		{
			out[i - start] = s[i];
			i++;
		}
		out[i - start] = '\0';
		return (out);
	}
}
