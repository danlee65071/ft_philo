NAME = philo

SRCS = philo.c philo_parser.c philo_utils.c philo_init.c philo_routine.c\
		philo_utils2.c philo_waiter.c

HEADER = philo.h

DIR_OBJS = objs
OBJS = $(patsubst %.c, %.o, $(SRCS))
PATH_OBJS = $(addprefix $(DIR_OBJS)/, $(OBJS))

CC = gcc

FLAGS = -Wall -Werror -Wextra -g -pthread

RM = rm -rf

all:$(NAME)

$(NAME): $(PATH_OBJS)
	$(CC) $(FLAGS) $^ -o $@

$(DIR_OBJS)/%.o: %.c $(HEADER) Makefile
	@mkdir -p $(DIR_OBJS)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(DIR_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re