FILES = ft_printf.c\


SRC_DIR = ./srcs/
SRC = $(addprefix $(SRC_DIR), $(FILES))

OBJECTS = $(SRC:.c=.o)

CC = cc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

all: $(NAME)

bonus: all

$(NAME): $(OBJECTS)
	@echo "Compiling ft_printf"
	@$(CC) $(CFLAGS) -c $(SRC)
	@ar -rs libftprintf.a $(OBJECTS)
	@echo "Done"

clean:
	@echo "Cleaning"
	@$(RM) $(OBJECTS)
	@echo "Done"

fclean: clean
	@echo "Removing"
	@$(RM) $(NAME) $(OBJECTS)
	@echo "Done"

re: fclean bonus

.PHONY:	all clean fclean re bonus
.SILENT:
