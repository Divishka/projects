#include "push_swap.h"

int	start_step(const int *stack_a, int size, int base, int *flag_1)
{
	int	step_1;
	int	i;

	i = 0;
	step_1 = 0;
	while (i < size)
	{
		while (stack_a[i] == 0)
		{
			i++;
			step_1--;
		}
		if (stack_a[i] <= base && stack_a[i] > 0)
		{
			step_1 += i;
			break ;
		}
		i++;
	}
	if (step_1 > size / 2)
		*flag_1 = 1;
	return (step_1);
}

int	end_step(const int *stack_a, int size, int *base, int i)
{
	int	tmp;
	int	step;

	tmp = size - 1;
	step = 0;
	while (tmp)
	{
		if (stack_a[tmp] <= *base && stack_a[tmp] != stack_a[i]
			&& stack_a[tmp] > 0)
		{
			step = tmp;
			break ;
		}
		tmp--;
	}
	if (step > size / 2)
	{
		step = size - step;
		*base = 1;
	}
	return (step);
}

int	find_hold_first(const int *stack_a, int size, int base, int *flag)
{
	int	i;
	int	step_2;
	int	step_1;
	int	flag_1;

	step_1 = 0;
	step_2 = 0;
	flag_1 = 0;
	step_1 = start_step(stack_a, size, base, &flag_1);
	i = step_1;
	if (step_1 > size / 2)
		step_1 = size - step_1;
	step_2 = end_step(stack_a, size, &base, i);
	if (step_2 > step_1)
	{
		*flag = flag_1;
		return (step_1);
	}
	*flag = base;
	return (step_2);
}

int	step_max(const int *stack_a, int maxim)
{
	int	step;
	int	i;

	step = 0;
	i = 0;
	while (stack_a[i] != maxim)
	{
		if (stack_a[i] == 0)
			step--;
		i++;
	}
	step += i + 1;
	return (step);
}

int	find_hold_second(const int stack_a[], int size, int *flag)
{
	int	step_1;
	int	step_2;
	int	maxim;
	int	max_index;

	*flag = 0;
	step_1 = 0;
	step_2 = 0;
	max_index = size - 1;
	maxim = max(stack_a, size);
	step_1 = step_max(stack_a, maxim);
	while (stack_a[max_index] != maxim)
	{
		while (stack_a[max_index] == 0)
			max_index--;
		step_2++;
		max_index--;
	}
	if (step_1 > step_2)
	{
		*flag = 1;
		return (step_2);
	}
	return (step_1);
}
