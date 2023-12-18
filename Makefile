
NAME = push_swap

SRCS =	src/commands.c	\
		src/error_check.c	\
		src/init_nodes.c	\
		src/main.c			\
		src/range.c			\
		src/rotate.c		\
		src/utils.c

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -Iincludes

RM = rm -rf

all: $(NAME) 
$(NAME): $(OBJS)
	@$(MAKE) -C ./libft
	@$(CC) $(CFLAGS) $(OBJS) ./libft/libft.a -o $(NAME)

clean: 
	@$(MAKE) -C ./libft fclean
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
