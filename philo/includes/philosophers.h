/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabertau <vabertau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 11:25:46 by vabertau          #+#    #+#             */
/*   Updated: 2024/05/27 11:25:47 by vabertau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H

# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

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

int						launch_threads(t_data *data, t_philosopher *philosopher,
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

void					destroy_mutex(t_data data, pthread_mutex_t *mutex);

// ==== THREAD_ERRORS ====

int						thread_create_error(int threads_launched,
							t_philosopher *philosopher, pthread_mutex_t *mutex,
							int mainthread_id);
int						thread_join_error(t_philosopher *philosopher,
							pthread_mutex_t *mutex);

// ==== CHECK_ARG ====

int						check_arg(int argc, char **argv);

// ==== LIBFT ====

int						ft_atoi(const char *nptr);
int						ft_isdigit(int c);
int						ft_printf(const char *str, ...);
int						ft_putptr(unsigned long long ptr);
int						ft_putstr(char *s);
int						ft_putnbrlen_fd(int n, int fd);
int						ft_putunslen_fd(unsigned int n, int fd);
int						ft_puthexa(unsigned long long ptr, char *table);
int						ft_puthexa2(unsigned int nb, char *table);
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char *s, int fd);
int						ft_strlen(const char *s);
void					ft_putnbr_fd(int n, int fd);

#endif
