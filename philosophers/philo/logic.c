#include "philo.h"

void	sleeping(t_philo *philo)
{
	printf("%zu: philo %d is sleeping\n", get_time(), philo->number);
	usleep(philo->data->sleeping_time * 1000);
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->t_mutexes[philo->number - 1]);
	if (philo->number == philo->data->philos_number)
		pthread_mutex_lock(&philo->data->t_mutexes[0]);
	else
		pthread_mutex_lock(&philo->data->t_mutexes[philo->number]);
	printf("%zu: philo %d has taken a fork\n", get_time(), philo->number);
	printf("%zu: philo %d is eating\n", get_time(), philo->number);
	philo->number_of_meals++;
	philo->time = get_time();
	usleep(philo->data->eating_time * 1000);
	pthread_mutex_unlock(&philo->data->t_mutexes[philo->number - 1]);
	if (philo->number == philo->data->philos_number)
		pthread_mutex_unlock(&philo->data->t_mutexes[0]);
	else
		pthread_mutex_unlock(&philo->data->t_mutexes[philo->number]);
	if (philo->number_of_meals == philo->data->meal_count)
		philo->data->count_of_full_philos++;
}

void	*dying_time_countdown(void *philo)
{
	long		time;
	t_philo		*ph;

	ph = ((t_philo *)philo);
	time = (long)ph->data->dying_time;
	ph->time = get_time();
	while (get_time() - ph->time <= time)
		usleep(100);
	ph->data->one_philo_is = DEAD;
	pthread_mutex_lock(&ph->data->t_mutexes[ph->data->philos_number]);
	printf("%zu: %d died\n", get_time(), ph->number);
	return (NULL);
}

void	*life_time(void *philo)
{
	while (1)
	{
		eating(philo);
		sleeping(philo);
		printf("%zu: philo %d is thinking\n", \
		get_time(), ((t_philo *)philo)->number);
	}
	return (NULL);
}

int	meal_up(t_data *data, int i)
{
	data->meal_countdown = (pthread_t *)malloc(sizeof(pthread_t) \
	* data->philos_number);
	data->die_countdown = (pthread_t *)malloc(sizeof(pthread_t) \
	* data->philos_number);
	create_mutexes(data);
	while (++i < data->philos_number)
	{
		if (pthread_create(&data->meal_countdown[i], \
		NULL, life_time, &data->philo[i]))
			return (write_error("failed thread"));
		if (pthread_create(&data->die_countdown[i], \
		NULL, dying_time_countdown, &data->philo[i]))
			return (write_error("failed thread"));
		if (pthread_detach(data->meal_countdown[i]))
			return (write_error("failed detach thread"));
		if (pthread_detach(data->die_countdown[i]))
			return (write_error("failed detach thread"));
	}
	while ((data->one_philo_is == ALIVE) \
	&& (data->count_of_full_philos != data->philos_number))
		usleep(10);
	destroy_mutexes(data);
	return (OK);
}
