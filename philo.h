#ifndef PHILO_H
#define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct timeval t_timeval;

typedef struct s_data
{
	int				num_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_must_eat;
	int				num_of_fed_up;
	pthread_mutex_t	forks[200];
	pthread_mutex_t	mutex_write;
	pthread_mutex_t	mutex_eat;
	t_timeval		start_time;
} t_data;

typedef struct s_philo
{
	int			right_fork;
	int			left_fork;
	int			philo_ind;
	pthread_t	philo_thread;
	int			num_of_eat;
	t_timeval	time_last_eat;
	t_data		*data;
} t_philo;

int				error_message(const char *message);
int				ft_atoi(const char *str);
int				philo_parser(int argc, char **argv, t_data *data);
int				philo_init(t_data *data, t_philo *philo);
unsigned long	timeval_to_ms(const t_timeval time);
void			print_message(t_data *data, int philo_ind, const char* message);
void			philo_usleep(int time);
int				philo_start(t_data *data, t_philo *philo);
void			philo_waiter(t_data *data, t_philo *philo);
unsigned long	get_current_time(t_data *data);

#endif