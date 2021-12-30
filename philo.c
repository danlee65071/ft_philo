#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo	philo[200];

	if (philo_parser(argc, argv, &data) != 0 || philo_init(&data, philo) != 0
		|| philo_start(&data, philo) != 0)
		return (1);
	philo_waiter(&data, philo);
	return (0);
}
