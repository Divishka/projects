#include "push_swap.h"

void	sa(int *stack_a, char *str)
{
	int		tmp;
	int		i;

	i = 0;
	while (stack_a[i] == 0)
		i++;
	tmp = stack_a[i];
	stack_a[i] = stack_a[i + 1];
	stack_a[i + 1] = tmp;
	ft_putstr(str);
}

void	rra(int *stack_a, int size, char *str)
{
	int	tmp;
	int	i;

	i = 0;
	while (stack_a[i] == 0)
	{
		i++;
		size--;
	}
	tmp = stack_a[i + size - 1];
	while (size > 1)
	{
		stack_a[i + size - 1] = stack_a[i + size - 2];
		size--;
	}
	stack_a[i] = tmp;
	ft_putstr(str);
}

void	ra(int *stack_a, int size, char *str)
{
	int	tmp;
	int	i;

	i = 0;
	while (stack_a[i] == 0)
	{
		i++;
		size--;
	}
	tmp = stack_a[i];
	while (size > 1)
	{
		stack_a[i] = stack_a[i + 1];
		i++;
		size--;
	}
	stack_a[i] = tmp;
	ft_putstr(str);
}

void	pb(int *stack_a, int *stack_b, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (*stack_b == 0)
		*stack_b = *stack_a;
	else
	{
		while (stack_b[i] != 0)
			i++;
		while (stack_a[j] == 0)
			j++;
		stack_b[i] = stack_a[j];
	}
	stack_a[j] = 0;
	ft_putstr(str);
}

void	pa(int *stack_a, int *stack_b, int size, char *str)
{
	int	j;

	j = 0;
	while (stack_b[size - 1] == 0)
		size--;
	while (stack_a[j] == 0 && j < size)
		j++;
	stack_a[j - 1] = stack_b[size - 1];
	stack_b[size - 1] = 0;
	ft_putstr(str);
}
