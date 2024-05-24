NAME = philo

CC = cc $(FLAGS) -g

FLAGS = -Wall -Werror -Wextra

FILENAMES = main.c init_data.c init_mutex.c launch_threads.c init_philosopher.c actions.c print_action.c \
setflags_routine.c get_time.c destroy_mutex.c thread_errors.c check_arg.c ft_atoi.c ft_isdigit.c \
ft_printf.c ft_putptr.c utils.c ft_putchar_fd.c ft_putstr_fd.c ft_strlen.c ft_putnbr_fd.c

SRCS = $(addprefix srcs/, $(FILENAMES))

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(FT_PRINTF) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

all: $(NAME)
