#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int		*stack_a;
	char	**str;
	char	c;

	c = '0';
	str = check_str(argv, &argc, &c);
	if (str == NULL)
		return (error());
	if (argc >= 2)
	{
		if (validate_value(str, argc - 1) == 0)
			return (error());
		stack_a = atoi_array(str, argc - 1, c);
		if (stack_a == NULL)
			return (error());
		if (perfect_array(stack_a, argc - 1) == 1)
			return (0);
		push_swap(stack_a, argc - 1);
		if (perfect_array(stack_a, argc - 1) == 0)
			return (error());
		free(stack_a);
	}
	return (0);
}
