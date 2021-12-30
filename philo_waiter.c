#include "philo.h"

void	philo_waiter(t_data *data, t_philo *philo)
{
	int			i;
	t_timeval	current_time;

	i = 0;
	usleep(200);
	while(1)
	{
		if (i == data->num_philos)
			i = 0;
		pthread_mutex_lock(&data->mutex_eat);
		gettimeofday(&current_time, NULL);
		if (timeval_to_ms(current_time)
			- timeval_to_ms(philo[i].time_last_eat) >
			(unsigned long)data->time_to_die)
		{
			pthread_mutex_lock(&data->mutex_write);
			printf("%ld %d %s\n", get_current_time(data),
				   philo[i].philo_ind, "died");
			break ;
		}
		pthread_mutex_unlock(&data->mutex_eat);
		if (data->num_of_fed_up >= data->num_philos)
		{
			pthread_mutex_lock(&data->mutex_write);
			break;
		}
		++i;
	}
}