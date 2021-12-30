#include "philo.h"

static void	philo_eat(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&data->forks[philo->right_fork]);
	print_message(data, philo->philo_ind, "has taken a fork");
	pthread_mutex_lock(&data->forks[philo->left_fork]);
	print_message(data, philo->philo_ind, "has taken a fork");
	pthread_mutex_lock(&data->mutex_eat);
	print_message(data, philo->philo_ind, "is eating");
	philo->num_of_eat++;
	gettimeofday(&philo->time_last_eat, NULL);
	if (philo->num_of_eat == data->num_must_eat)
		data->num_of_fed_up++;
	pthread_mutex_unlock(&data->mutex_eat);
	philo_usleep(data->time_to_eat);
	pthread_mutex_unlock(&data->forks[philo->right_fork]);
	pthread_mutex_unlock(&data->forks[philo->left_fork]);
}

static void	*philo_routine(void *void_philo)
{
	t_data	*data;
	t_philo	*philo;

	philo = (t_philo*)void_philo;
	data = philo->data;
	if (philo->philo_ind % 2 == 0)
		usleep(200);
	while (1)
	{
		philo_eat(data, philo);
		print_message(data, philo->philo_ind, "is sleeping");
		philo_usleep(data->time_to_sleep);
		print_message(data, philo->philo_ind, "is thinking");
	}
	return (NULL);
}

int	philo_start(t_data *data, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < data->num_philos)
	{
		if (pthread_create(&philo[i].philo_thread, NULL, philo_routine,
						   (void *)(&philo[i])) != 0)
			return error_message("Thread creation failed!\n");
		if (pthread_detach(philo[i].philo_thread) != 0)
			return error_message("Thread detach failed!\n");
	}
	return (0);
}