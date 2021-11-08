#include "philo.h"

void	create_mutexes(t_data *data)
{
	int	i;

	i = -1;
	while (++i <= data->philos_number)
		pthread_mutex_init(&data->t_mutexes[i], NULL);
}

void	destroy_mutexes(t_data *data)
{
	int	i;

	i = -1;
	while (++i <= data->philos_number)
		pthread_mutex_destroy(&data->t_mutexes[i]);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (args_valid_check(argc, argv) == ERROR)
		return (ERROR);
	if (read_data(&data, argv) == ERROR)
		return (ERROR);
	if (meal_up(&data, -1) == ERROR)
		return (ERROR);
	return (OK);
}
