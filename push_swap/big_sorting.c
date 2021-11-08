#include "push_swap.h"

int	steck_not_empty(const int *stack_a, int size)
{
	int	i;

	i = 0;
	while (size)
	{
		if (stack_a[i] != 0)
			return (1);
		i++;
		size--;
	}
	return (0);
}

void	on_b(int *stack_a, int *stack_b, int size, int base)
{
	int	index;
	int	flag;
	int	i;
	int	step;

	step = base;
	flag = 0;
	i = 0;
	while (steck_not_empty(stack_a, size) == 1)
	{
		index = find_hold_first(stack_a, size, base, &flag);
		while (index > 0)
		{
			if (flag == 1)
				rra(stack_a, size, "rra\n");
			else
				ra(stack_a, size, "ra\n");
			index--;
		}
		pb(stack_a, stack_b, "pb\n");
		i += 1;
		if (base == i)
			base += step;
	}
}

void	on_a(int *stack_a, int *stack_b, int size)
{
	int	index;
	int	flag;

	flag = 0;
	while (steck_not_empty(stack_b, size) == 1)
	{
		index = find_hold_second(stack_b, size, &flag);
		while (index > 0)
		{
			if (flag == 1)
				rb(stack_b, size, "rb\n");
			else
				rrb(stack_b, size, "rrb\n");
			index--;
		}
		pa(stack_a, stack_b, size, "pa\n");
		size--;
	}
}

void	big_sorting(int *stack_a, int *stack_b, int size)
{
	int	base;

	if (size <= 100)
		base = 20;
	else
		base = 45;
	on_b(stack_a, stack_b, size, base);
	on_a(stack_a, stack_b, size);
}
