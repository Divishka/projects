#include "push_swap.h"

size_t	ft_count(const char *str)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		while (*str == ' ')
			str++;
		if (*str)
		{
			count++;
			while (*str && *str != ' ')
				str++;
		}
	}
	return (count);
}

int	check_two(char *str)
{
	while (*str)
	{
		if (*str == '-' || *str == '+')
			str++;
		if (ft_isdigit(*str) == 1 || *str == ' ')
			str++;
		else
			return (0);
	}
	return (1);
}

char	**check_str(char **argv, int *argc, char *c)
{
	char	**str;

	str = argv;
	if (*argc == 2 && check_two(argv[1]) == 1)
	{
		*argc = (int)ft_count(argv[1]) + 1;
		str = ft_split(argv[1], ' ');
		if (str == NULL)
			return (NULL);
		*c = 'F';
	}
	return (str);
}
