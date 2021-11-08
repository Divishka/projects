#include "push_swap.h"

void	size_2_3_help(int *stack_a, int size, int i)
{
	if (stack_a[i] > stack_a[i + 1] && stack_a[i + 2] > stack_a[i + 1]
		&& stack_a[i + 2] > stack_a[i])
		sa(stack_a, "sa\n");
	else if ((stack_a[i] > stack_a[i + 1] && stack_a[i + 2] < stack_a[i + 1]
			  && stack_a[i + 2] < stack_a[i]))
	{
		sa(stack_a, "sa\n");
		rra(stack_a, size, "rra\n");
	}
	else if ((stack_a[i] > stack_a[i + 1] && stack_a[i + 2] > stack_a[i + 1]
			  && stack_a[i + 2] < stack_a[i]))
		ra(stack_a, size, "ra\n");
	else if ((stack_a[i] < stack_a[i + 1] && stack_a[i + 2] < stack_a[i + 1]
			  && stack_a[i + 2] > stack_a[i]))
	{
		sa(stack_a, "sa\n");
		ra(stack_a, size, "ra\n");
	}
	else if ((stack_a[i] < stack_a[i + 1] && stack_a[i + 2] < stack_a[i + 1]
			  && stack_a[i + 2] < stack_a[i]))
		rra(stack_a, size, "rra\n");
}

void	size_2_or_3(int *stack_a, int size)
{
	int	i;

	i = 0;
	if (*stack_a > *(stack_a + 1) && size == 2)
	{
		sa(stack_a, "sa\n");
		return ;
	}
	while (stack_a[i] == 0)
		i++;
	size_2_3_help(stack_a, size, i);
}

void	size_4(int *stack_a, int *stack_b, int size)
{
	int	i;
	int	index;

	i = 0;
	if (stack_a[i] == 0)
		i++;
	while (stack_a[i] != min(stack_a, size, &index))
	{
		if (index > 2)
			rra(stack_a, size, "rra\n");
		else
			ra(stack_a, size, "ra\n");
	}
	pb(stack_a, stack_b, "pb\n");
	size_2_or_3(stack_a, size);
	pa(stack_a, stack_b, size, "pa\n");
}

void	size_4_or_5(int *stack_a, int *stack_b, int size)
{
	int	index;

	if (size == 4)
		size_4(stack_a, stack_b, size);
	else
	{
		while (stack_a[0] != min(stack_a, size, &index))
		{
			if (index > 2)
				rra(stack_a, size, "rra\n");
			else
				ra(stack_a, size, "ra\n");
		}
		pb(stack_a, stack_b, "pb\n");
		size_4(stack_a, stack_b, size);
		pa(stack_a, stack_b, size, "pa\n");
	}
}

int	*push_swap(int *stack_a, int size)
{
	int	*stack_b;

	stack_b = calloc(size, sizeof(int));
	if (size <= 3)
		size_2_or_3(stack_a, size);
	else if (size <= 5)
		size_4_or_5(stack_a, stack_b, size);
	else
	{
		big_sorting(stack_a, stack_b, size);
	}
	free(stack_b);
	return (stack_a);
}
