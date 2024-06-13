The dining philosophers problem involves a group of philosophers sitting at a round table, each with their own plate of spaghetti. 

There are as many forks as there are philosophers. 

The challenge is to design a protocol where each philosopher can alternate between eating and thinking without starving, 
even though they can only eat when they have both a left and right fork available. 

Philosophers don’t speak to each other, and they don’t know if another philosopher is about to die. 

The simulation stops when a philosopher dies of starvation

Each philosopher represents a separate thread, and synchronization mechanisms (mutexes) are used.

The challenge lies in preventing deadlocks and ensuring that all philosophers get a chance to eat while avoiding starvation.

Usage : ./philo 		number_of_philosophers 		time_to_die time_to_eat time_to_sleep 		[number_of_times_each_philosopher_must_eat]
