#include "push_swap.h"

void	rrb(int *stack_a, int size, char *str)
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

void	rb(int *stack_a, int size, char *str)
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
