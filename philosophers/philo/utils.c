#include "philo.h"

long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((long)(time.tv_sec * 1000 + time.tv_usec / 1000));
}

int	check_is_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (ERROR);
		i++;
	}
	return (OK);
}

int	write_error(char *str)
{
	printf("%s\n", str);
	return (ERROR);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	k;

	i = 0;
	sign = 1;
	k = 0;
	if (!str[i])
		return (0);
	while (str[i] == '\t' || str[i] == '\v' || str[i] == '\n' \
			|| str[i] == '\r' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		k = (k * 10) + (str[i++] - '0');
	return (k * sign);
}
