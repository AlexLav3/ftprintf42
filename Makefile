NAME = libftprintf.a
CFLAGS = -Wall -Werror -Wextra
SOURCES = ft_atoi.c ft_check_arg.c ft_chosehex.c ft_hexlower.c ft_hexupper.c ft_pointer.c ft_printf.c ft_putchar_onear.c ft_putchar.c ft_putnbr.c\
ft_putnewl.c ft_putstr.c ft_putunsint.c ft_chosenbr.c

OBJECTS = $(SOURCES:.c=.o)

all:${NAME} ${OBJECTS}

${NAME} : ${OBJECTS}
	ar rcs ${NAME} ${OBJECTS}

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f ${NAME}

re: fclean all
