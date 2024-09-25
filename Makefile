NAME = libft.a
CFLAGS = -Wall -Werror -Wextra
SOURCES = ft_isalnum.c ft_isalpha.c ft_isdigit.c ft_isprint.c ft_printf.c ft_putchar.c\
ft_putnbr.c ft_putnewl.c ft_putstr.c ft_strlen.c

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
