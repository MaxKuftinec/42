NAME := libft.a
AR := ar rcs
LIB := ranlib

all: clean

${NAME}:	${OBJS} # hello1.o hello2.o
	${AR} ${NAME} ${OBJS} # ar rcs libft.a hello1.o hello2.o
	${LIB} ${NAME}
clean:
	echo "Cleaning"
fclean:

re: