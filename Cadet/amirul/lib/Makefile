SRCS = ft_strlen.c ft_putstr.c

OBJS = ${SRCS:.c=.o}
NAME = libft.a

.c.o:
	echo Crazy
	cc -Wall -Wextra -Werror -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
		ar rcs libft.a ${OBJS}

src:
		echo ${SRCS}

all:
		echo ${OBJS}

clean:
		rm -rf *.o

fclean: clean
		rm libft.a