NAME = philosophers

CC = cc $(FLAGS) -g

FLAGS = -Wall -Werror -Wextra

FILENAMES = main.c init_data.c init_mutex.c launch_threads.c init_philosopher.c actions.c print_action.c \
setflags_routine.c get_time.c destroy_mutex.c thread_errors.c

SRCS = $(addprefix srcs/, $(FILENAMES))

OBJS = $(SRCS:.c=.o)

FT_PRINTF = libftprintf/libftprintf.a

FT_PRINTF_PATH = libftprintf

$(NAME): $(FT_PRINTF) $(OBJS)
	$(CC) $(OBJS) $(FT_PRINTF) -o $(NAME)

$(FT_PRINTF):
	make -C $(FT_PRINTF_PATH) all

clean:
	make -C $(FT_PRINTF_PATH) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(FT_PRINTF_PATH) fclean
	rm -f $(NAME)

re: fclean all

all: $(NAME)
