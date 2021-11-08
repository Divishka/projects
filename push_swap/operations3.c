#include "push_swap.h"

void	rr(int *stack_a, int *stack_b, int size, char *str)
{
	int	size_b;
	int	i;

	i = 0;
	size_b = 0;
	while (size_b < size)
	{
		if (stack_b[i] != 0)
			size_b++;
		i++;
	}
	ra(stack_a, size, "");
	rb(stack_b, size_b, "");
	ft_putstr(str);
}

void	rrr(int *stack_a, int *stack_b, int size, char *str)
{
	int	size_b;
	int	i;

	i = 0;
	size_b = 0;
	while (size_b < size)
	{
		if (stack_b[i] != 0)
			size_b++;
		i++;
	}
	rra(stack_a, size, "");
	rrb(stack_b, size_b, "");
	ft_putstr(str);
}

void	sb(int *stack_b, int size, char *str)
{
	int		tmp;

	while (stack_b[size] == 0)
		size--;
	tmp = stack_b[size];
	stack_b[size] = stack_b[size - 1];
	stack_b[size + 1] = tmp;
	ft_putstr(str);
}

void	ss(int *stack_a, int *stack_b, char *str, int size)
{
	int	size_b;
	int	i;

	i = 0;
	size_b = 0;
	while (size_b < size)
	{
		if (stack_b[i] != 0)
			size_b++;
		i++;
	}
	sb(stack_b, size_b, "");
	sa(stack_a, "");
	ft_putstr(str);
}
