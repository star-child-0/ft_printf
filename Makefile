NAME 	= libftprintf.a

CC 		= clang

CFLAGS	= -Wall -Wextra -Werror

SRCS	= ft_printf.c ft_printf_assembly_line.c ft_printf_format.c

OBJS	= $(SRCS:.c=.o)

AR		= ar -rcs

RM 		= rm -f

all: $(NAME)

$(NAME): $(OBJS)
	cd libft && make
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)
	cd libft && make clean

fclean: clean
	$(RM) $(NAME)
	cd libft && make fclean

bonus: all

re: fclean all

.SILENT:
