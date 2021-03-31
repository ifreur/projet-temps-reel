CC=gcc
CFLAG=-Wall
EXEC=make_proj main drawing clean
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
DRAWFLAG= `pkg-config --cflags --libs MagickWand`


all: $(EXEC)

main: $(OBJ) lib_sorted_job_list/sorted_job_list.o
	$(CC) -o $@ $^ 

%.o: %.c ordo.h
	$(CC) -o $@ -c $< $(CFLAGS)

drawing: graph/draw.o ordo.o lib_sorted_job_list/sorted_job_list.o
	$(CC) -o $@ $^ $(DRAWFLAG)

graph/%.o: graph/%.c 
	$(CC) -o $@ -c $< $(DRAWFLAG)*

make_proj:
	cd lib_sorted_job_list && make all

.PHONY: clean mrproper

clean:
	rm -f *.o graph/*.o
	cd lib_sorted_job_list && make clean

mrproper: clean
	rm -rf $(EXEC) 
	cd lib_sorted_job_list && make mrproper


