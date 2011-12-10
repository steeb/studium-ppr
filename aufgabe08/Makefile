CC      = /usr/bin/gcc
DEBUG	= -g
CFLAGS  = -Wall -Wextra -std=c89 -pedantic-errors -c
LFLAGS	= -Wall -Wextra

OBJ		= main.o binary_heap.o
OBJD	= main.od binary_heap.od

EXE		= binaryHeap

all: $(EXE) doxygen

$(EXE): $(OBJ)
	$(CC) $(LFLAGS) -o $@ $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) $<

debug: $(OBJD)
	$(CC) $(LFLAGS) $(DEBUG) -o $(EXE)$@ $(OBJD)

%.od: %.c
	$(CC) $(CFLAGS) $(DEBUG) -o $@ $<

check: splint

splint:
	splint *.c *.h -weak -booltype BOOL -boolfalse FALSE -booltrue TRUE +predboolint +noret +usedef +infloops +casebreak -initallelements -incompletetype -fixedformalarray

doc: doxygen

doxygen:
	doxygen ../ppr_doxygen.cfg

clean:
	rm *.o *.od

cleanall:
	rm -r $(EXE) *.o doxygen; rm *.od
