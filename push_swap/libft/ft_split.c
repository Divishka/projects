#include "libft.h"

static	size_t	ft_count(const char *str, char separate)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		while (*str == separate)
			str++;
		if (*str)
		{
			count++;
			while (*str && *str != separate)
				str++;
		}
	}
	return (count);
}

static	char	*ft_word(const char **src, char separate)
{
	size_t	i;
	char	*dst;

	i = 0;
	while ((*src)[i] && (*src)[i] != separate)
		i++;
	dst = ft_substr(*src, 0, i);
	if (dst == NULL)
		return (NULL);
	*src += i;
	return (dst);
}

static	void	*ft_clear(char **words, size_t i)
{
	while (i--)
	{
		free(words[i]);
	}
	free (words);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**mas_str;
	size_t	i;
	size_t	count;

	i = 1;
	if (s == NULL)
		return (NULL);
	count = ft_count(s, c) + 1;
	mas_str = (char **)malloc(sizeof(char *) * (count + 1));
	if (mas_str == NULL)
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			mas_str[i] = ft_word(&s, c);
			if (mas_str[i] == NULL)
				return (ft_clear(mas_str, i - 1));
			i++;
		}
	}
	mas_str[i] = NULL;
	return (mas_str);
}
