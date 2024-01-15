CC=gcc
INCDIRS=-I
OPT=-O0
CFLAGS = -Wall -Wextra -g $(INCDIR) $(OPT) 

CFILES = main.c math_decode.c parenthesis.c stack.c
OBJECTS = main.o math_decode.o parenthesis.o stack.o

BINARY=bin

all: $(BINARY)

$(BINARY): $(OBJECTS)
	@echo "Compiling Output files" 
	$(CC) -o $@ $^ -lm

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^ -lm


clean:
	rm *.o $(BINARY)