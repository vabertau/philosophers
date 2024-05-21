#ifndef PHILOSOPHERS_H

# define PHILOSOPHERS_H

# include "../libftprintf/ft_printf.h"
# include <pthread.h>

typedef struct s_data
{
	int	nb_philos;
	int	t_teat;
	int	t_tdie;
	int	t_tsleep;
	int	nb_teat;
}		t_data;

typedef struct s_philosopher
{
	t_data		*data;
	pthread_t	thread_id;
}		t_philosopher;

// ==== INIT_DATA ====

void	init_data(char **argv, t_data *data);

// ==== INIT_MUTEX ====

void	init_mutex(t_data *data, pthread_mutex_t *mutex);

// ==== INIT_PHILOSOPHER ====

void	init_philosopher(t_data *data, t_philosopher *philosopher);

// ==== LAUNCH_THREADS ====

void	launch_threads(t_data *data, t_philosopher *philosopher, pthread_mutex_t *mutex);

// ==== ACTIONS ====

void	eat(t_philosopher *philosopher);
void	ft_sleep(t_philosopher *philosopher);
void	think(void);

#endif
