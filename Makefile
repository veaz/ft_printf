SRCS = 	src/ft_printf.c \
		src/ft_utils_base.c \
		src/ft_utils.c

NAME = libftprintf.a
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
OBJS = $(SRCS:.c=.o)
AR = ar -rcs
CC = gcc -c

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
