CC      = /usr/bin/gcc
DEBUG	= -g
CFLAGS  = -Wall -Wextra -std=c89 -pedantic-errors -c
LFLAGS	= -Wall -Wextra

OBJ		= main.o gol.o
OBJD	= main.od gol.od

EXE		= gol

all: splint $(EXE) doxygen

$(EXE): $(OBJ)
	$(CC) $(LFLAGS) -o $@ $< 

%.o: %.c
	$(CC) $(CFLAGS) $<

debug: $(OBJD)
	$(CC) $(LFLAGS) $(DEBUG) -o $(EXE)$@ $<

%.od: %.c
	$(CC) $(CFLAGS) $(DEBUG) -o $@ $<

check: splint

splint:
	splint *.c -weak -booltype BOOL -boolfalse FALSE -booltrue TRUE +predboolint +noret +usedef +infloops +casebreak -initallelements -incompletetype -fixedformalarray

doc: doxygen

doxygen:
	doxygen ../ppr_doxygen.cfg

clean:
	rm *.o *.od

cleanall:
	rm -r $(EXE) *.o doxygen; rm *.od
