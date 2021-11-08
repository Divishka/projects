#include "philo.h"

static int	read_philos(t_data *data)
{
	int	i;

	data->philo = (t_philo *)malloc(sizeof(t_philo) * data->philos_number);
	if (!data->philo)
		return (write_error("failed memory allocation"));
	i = 0;
	while (i < data->philos_number)
	{
		data->philo[i].number = i + 1;
		data->philo[i].data = data;
		data->philo[i].number_of_meals = 0;
		i++;
	}
	return (OK);
}

int	read_data(t_data *data, char **argv)
{
	data->philos_number = ft_atoi(argv[1]);
	data->dying_time = ft_atoi(argv[2]);
	data->eating_time = ft_atoi(argv[3]);
	data->sleeping_time = ft_atoi(argv[4]);
	if (argv[5])
		data->meal_count = ft_atoi(argv[5]);
	else
		data->meal_count = -1;
	data->one_philo_is = ALIVE;
	data->t_mutexes = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) \
	* (data->philos_number + 1));
	data->count_of_full_philos = 0;
	if (read_philos(data) == ERROR)
		return (ERROR);
	return (OK);
}
