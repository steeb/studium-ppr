CC      = /usr/bin/gcc
CFLAGS  = -Wall -std=c89

all: hello_world temperaturumwandlung

hello_world: hello_world.o

temperaturumwandlung: temperaturumwandlung.o

%: %.o
	$(CC) $(CFLAGS) -o $@ $< 

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm *.o

cleanall:
	rm *.o hello_world temperaturumwandlung
