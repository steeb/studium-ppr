CC      = /usr/bin/gcc
DEBUG	= -g
CFLAGS  = -Wall -Wextra -std=c89 -pedantic-errors -c
LFLAGS	= -Wall -Wextra

OBJ		= main.o rsa_keys.o crypt.o ui.o
OBJD	= main.od rsa_keys.od crypt.od ui.od

EXE		= rsa

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
