CC      = /usr/bin/gcc
DEBUG	= -g
CFLAGS  = -Wall -Wextra -std=c89 -pedantic-errors -c
LFLAGS	= -Wall -Wextra

OBJ		= main.o string_formatter.o
OBJD	= main.od rsa_string_formatter.o

EXE		= stringFormatter

all: splint $(EXE) doxygen

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
	splint *.c -weak -booltype BOOL -boolfalse FALSE -booltrue TRUE +predboolint +noret +usedef +infloops +casebreak -initallelements -incompletetype -fixedformalarray

doc: doxygen

doxygen:
	doxygen ../ppr_doxygen.cfg

clean:
	rm *.o *.od

cleanall:
	rm -r $(EXE) *.o doxygen; rm *.od
