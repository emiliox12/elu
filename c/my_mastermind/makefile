CC := gcc
CC := ${CC}
OUTPUT := mastermind

all: my_mastermind 

my_mastermind: 
	@echo Compiling
	@${CC} my_mastermind.c -o ${OUTPUT};
	@echo "Compiled to ${OUTPUT}"

clean: 
	# rm *.o

fclean: clean 
	rm ${OUTPUT}

re: fclean all
