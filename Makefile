SRCS = 	src/ft_printf.c \
		src/ft_utils_base.c \
		src/ft_utils.c

NAME = libftprintf.a
CFLAGS = -Wall -Werror -Wextra -I ./include
RM = rm -f
OBJS = $(SRCS:.c=.o)
AR = ar -rcs
CC = gcc -c

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)
	@echo "\x1b[32mCompilation successful\x1b[0m"

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
