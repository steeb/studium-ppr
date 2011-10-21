CC      = /usr/bin/gcc
DEBUG	= -g
CFLAGS  = -Wall -std=c89 -c $(DEBUG)
LFLAGS	= -Wall $(DEBUG)

OBJ = main.o ulam.o

all: ulam

ulam: $(OBJ)
	$(CC) $(LFLAGS) -o $@ $< 

%.o: %.c
	$(CC) $(CFLAGS) $<

clean:
	rm *.o

cleanall:
	rm ulam *.o	
