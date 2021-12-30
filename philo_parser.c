#include "philo.h"

static int check_params(int argc, t_data *data)
{
	if (data->num_philos <= 0 || data->time_to_die <= 0
		|| data->time_to_eat <= 0 || data->time_to_sleep <= 0)
		return error_message("Wrong arguments!\n");
	if (data->num_philos > 200)
		return error_message("Too many philosophers!\n");
	if (argc == 6 && data->num_must_eat <= 0)
		return error_message("Wrong arguments!\n");
	return (0);
}

int	philo_parser(int argc, char **argv, t_data *data)
{
	if (argc != 5 && argc != 6)
		return error_message("Wrong number of arguments!\n");
	data->num_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->num_must_eat = ft_atoi(argv[5]);
	else
		data->num_must_eat = -1;
	data->num_of_fed_up = 0;
	return check_params(argc, data);
}
