# Variables
CC = gcc
CFLAGS = -Wall -Wextra -g

# Objetivo principal
all: lab6

lab6: main.c
	$(CC) $(CFLAGS) -o lab6 main.c

# Limpiar archivos generados
clean:
	rm -f lab6


