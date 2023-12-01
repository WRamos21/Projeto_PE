all: client

client: client.o bignumber.o
	gcc client.o bignumber.o -lm -o client

client.o: client.c bignumber.h
	gcc -std=c99 -g -Wall -Werror -c client.c

bignumber.o: bignumber.c bignumber.h
	gcc -std=c99 -g -Wall -Werror -c bignumber.c
