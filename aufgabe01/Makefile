CC      = /usr/bin/gcc
DEBUG	= -g
CFLAGS  = -Wall -std=c89 -c $(DEBUG)
LFLAGS	= -Wall $(DEBUG)

all: hello_world temperaturumwandlung temperaturumwandlung2

hello_world: hello_world.o

temperaturumwandlung: temperaturumwandlung.o

temperaturumwandlung2: temperaturumwandlung2.o

%: %.o
	$(CC) $(LFLAGS) -o $@ $< 

%.o: %.c
	$(CC) $(CFLAGS) $<

clean:
	rm *.o

cleanall:
	rm *.o hello_world temperaturumwandlung temperaturumwandlung2
