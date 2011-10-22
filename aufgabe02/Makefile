CC      = /usr/bin/gcc
DEBUG	= -g
CFLAGS  = -Wall -std=c89 -c
LFLAGS	= -Wall

OBJ		= main.o ulam.o
OBJD	= main.od ulam.od

all: splint ulam doxygen

ulam: $(OBJ)
	$(CC) $(LFLAGS) -o $@ $< 

%.o: %.c
	$(CC) $(CFLAGS) $<

debug: $(OBJD)
	$(CC) $(LFLAGS) $(DEBUG) -o $@ $<

%.od: %.c
	$(CC) $(CFLAGS) $(DEBUG) -o $@ $<

check: splint

splint:
	splint *.c -weak -booltype BOOL -boolfalse FALSE -booltrue TRUE +predboolint +noret +usedef +infloops +casebreak -initallelements -incompletetype -fixedformalarray

doc: doxygen

doxygen:
	doxygen ../ppr_doxygen.cfg

clean:
	rm *.o

cleanall:
	rm -r ulam *.o doxygen
