#include "push_swap.h"

static int	check_min(char **argv, int *min, int *size)
{
	int	i;

	i = 1;
	if (argv[i] == NULL)
	{
		while (argv[i] == NULL)
		{
			i++;
			(*size)--;
		}
		if (argv[i] != NULL)
			*min = ft_atoi(argv[i]);
	}
	else
		*min = ft_atoi(argv[i]);
	return (i);
}

static void	find_min(int size, int *index, char **argv)
{
	int		i;
	long	arg;
	int		min;

	i = check_min(argv, &min, &size);
	*index = i;
	while (size > 0)
	{
		if (argv[i] != NULL)
		{
			arg = ft_atoi(argv[i]);
			if (arg < min)
			{
				min = arg;
				*index = i;
			}
		}
		i++;
		size--;
	}
}

int	*atoi_array(char **argv, int size, char c)
{
	int		*stack_a;
	int		min;
	int		index;
	int		save_size;

	min = 1;
	stack_a = malloc(sizeof(int) * (size));
	if (stack_a == NULL)
		return (NULL);
	save_size = size;
	while (size > 0)
	{
		find_min(save_size, &index, argv);
		stack_a[index - 1] = min;
		if (c == 'F')
			free(argv[index]);
		argv[index] = NULL;
		size--;
		min++;
	}
	if (c == 'F')
		free(argv);
	return (stack_a);
}

int	max(const int stack_a[], int size)
{
	int	i;
	int	max;

	i = 0;
	while (stack_a[i] == 0)
	{
		i++;
		size--;
	}
	max = stack_a[i];
	while (size--)
	{
		if (stack_a[i] > max)
			max = stack_a[i];
		i++;
	}
	return (max);
}
