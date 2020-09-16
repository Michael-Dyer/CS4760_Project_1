
CC = gcc
CFLAGS = -g 

OBJS=
OBJS2=
OBJS3=

all: proc_fan runsim testsim

proc_fan:$(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) 

runsim:$(OBJS2)
	$(CC) $(CFLAGS) -o $@ $(OBJS2) 

testsim:$(OBJS3) 
	$(CC) $(CFLAGS) -c 


clean:
	rm -f *.o
