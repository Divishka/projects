#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>

# define ERROR 1
# define OK 0
# define ALIVE 0
# define DEAD 1
# define NO 0
# define YES 1

typedef struct s_philo
{
	int				number;
	long			time;
	int				number_of_meals;
	struct s_data	*data;
}				t_philo;

typedef struct s_data
{
	int				philos_number;
	int				dying_time;
	int				eating_time;
	int				sleeping_time;
	int				meal_count;
	int				count_of_full_philos;
	int				one_philo_is;
	t_philo			*philo;
	pthread_mutex_t	*t_mutexes;
	pthread_t		*meal_countdown;
	pthread_t		*die_countdown;
}				t_data;

int		ft_atoi(const char *str);
int		check_is_digit(char *str);
int		write_error(char *str);
long	get_time(void);
int		read_data(t_data *data, char **argv);
int		args_valid_check(int argc, char **argv);
int		meal_up(t_data *data, int i);
void	create_mutexes(t_data *data);
void	destroy_mutexes(t_data *data);

#endif
