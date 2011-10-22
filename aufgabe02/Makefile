CC      = /usr/bin/gcc
DEBUG	= -g
CFLAGS  = -Wall -std=c89 -c $(DEBUG)
LFLAGS	= -Wall $(DEBUG)

OBJ = main.o ulam.o

all: splint ulam doxygen

ulam: $(OBJ)
	$(CC) $(LFLAGS) -o $@ $< 

%.o: %.c
	$(CC) $(CFLAGS) $<

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
