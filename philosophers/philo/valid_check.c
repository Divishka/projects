#include "philo.h"

int	args_valid_check(int argc, char **argv)
{
	long	a1;
	long	a2;
	long	a3;
	long	a4;
	int		a5;

	if (argc != 5 && argc != 6)
		return (write_error("wrong arguments"));
	a1 = ft_atoi(argv[1]);
	a2 = ft_atoi(argv[2]);
	a3 = ft_atoi(argv[3]);
	a4 = ft_atoi(argv[4]);
	if (argv[5])
	{
		if (check_is_digit(argv[5]) == OK)
			a5 = ft_atoi(argv[5]);
		else
			return (write_error("wrong arguments"));
	}
	if (a1 <= 0 || a2 <= 0 || a3 <= 0 || a4 <= 0 || (a5 && a5 <= 0))
		return (write_error("wrong arguments"));
	return (OK);
}
