CC      = /usr/bin/gcc
CFLAGS  = -Wall -std=c89

OBJ = hello_world 

prog: $(OBJ)
	        $(CC) $(CFLAGS) -o prog $(OBJ)

%.o: %.c
	        $(CC) $(CFLAGS) -c $<
