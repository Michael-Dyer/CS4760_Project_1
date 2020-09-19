CC = gcc

all: proc_fan testsim

proc_fan: proc_fan.c
	$(CC) -o proc_fan proc_fan.c 


testsim: testsim.c 
	$(CC) -o testsim testsim.c 


clean:
	rm *.o proc_fan testsim
