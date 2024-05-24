#ifndef PHILOSOPHERS_H

# define PHILOSOPHERS_H

# include "../libftprintf/ft_printf.h"
# include <pthread.h>
# include <stdbool.h>
# include <sys/time.h>

typedef struct s_data
{
	int					nb_philos;
	int					t_teat;
	unsigned long long	t_tdie;
	int					t_tsleep;
	bool				end_flag;
	unsigned long long	t_start;
	int					max_meals;
}						t_data;

typedef struct s_philosopher
{
	t_data				*data;
	int					index;
	pthread_mutex_t		*mutex_lfork;
	pthread_mutex_t		*mutex_rfork;
	pthread_mutex_t		*mutex_write;
	pthread_mutex_t		*mutex_endflag;
	pthread_mutex_t		*mutex_tlastmeal;
	pthread_t			thread_id;
	unsigned long long	t_lastmeal;
	int					count_meals;
}						t_philosopher;

// ==== INIT_DATA ====

void					init_data(int argc, char **argv, t_data *data);

// ==== INIT_MUTEX ====

void					init_mutex(t_data *data, pthread_mutex_t *mutex);

// ==== INIT_PHILOSOPHER ====

void					init_philosopher(t_data *data,
							t_philosopher *philosopher, pthread_mutex_t *mutex);

// ==== THREADS ====

void					launch_threads(t_data *data, t_philosopher *philosopher,
							pthread_mutex_t *mutex);
void					*setflags_routine(void *philosopher);

// ==== ACTIONS ====

void					eat(t_philosopher *philosopher);
void					ft_sleep(t_philosopher *philosopher);
void					think(t_philosopher *philosopher);

// ==== PRINT_ACTIONS ====

void					print_fork(t_philosopher *philosopher);
void					print_sleep(t_philosopher *philosopher);
void					print_think(t_philosopher *philosopher);
void					print_eat(t_philosopher *philosopher);
void					print_died(t_philosopher *philosopher);

// ==== TIME ====

unsigned long long		get_time(void);
int						ft_usleep(size_t milliseconds);

// ==== DESTROY_MUTEX ====

void	destroy_mutex(t_data data, pthread_mutex_t *mutex);

#endif
