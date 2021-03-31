CC=gcc
CFLAGS=-W -Wall -ansi -pedantic
LDFLAGS=
EXEC=test_list
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)

all: $(EXEC)

test_list: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c sorted_job_list.h
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
