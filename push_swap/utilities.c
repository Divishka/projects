#include "push_swap.h"

int	check(char **s, char *c, int index)
{
	int	i;

	i = 1;
	while (i < index)
	{
		if (ft_strcmp(s[i], c) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_strdigit(char *str)
{
	while (*str)
	{
		if (*str == '-' || *str == '+')
			str++;
		if (ft_isdigit(*str) == 1)
			str++;
		else
			return (0);
	}
	return (1);
}

int	validate_value(char **argv, int size)
{
	int	i;

	i = 1;
	while (size > 0)
	{
		if (ft_is_strdigit(argv[i]) == 0)
			return (0);
		if (check(argv, argv[i], i) == 0)
			return (0);
		if (ft_atoi(argv[i]) > 2147483647 || ft_atoi(argv[i]) < -2147483648)
			return (0);
		i++;
		size--;
	}
	return (1);
}

int	perfect_array(int *stack_a, int size)
{
	int	i;

	i = 1;
	while (i < size)
	{
		if (stack_a[i - 1] > stack_a[i])
			return (0);
		i++;
	}
	return (1);
}

int	min(int *stack_a, int size, int *index)
{
	int	i;
	int	min;

	i = 0;
	*index = i;
	while (stack_a[i] == 0)
	{
		i++;
		size--;
	}
	min = stack_a[i];
	while (size--)
	{
		if (stack_a[i] < min)
		{
			min = stack_a[i];
			*index = i;
		}
		i++;
	}
	return (min);
}
