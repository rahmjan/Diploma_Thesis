CC=    gcc
LD=    gcc

DFLAGS  = -D "aligned_alloc(x,y)=malloc(y)" $(B_FLAGS)
CFLAGS  = -std=c99 $(DFLAGS)
INCPATH = -I/usr/local/include -I/opt/local/include -I/usr/include -I.
LDFLAGS =
LIBPATH = -L/usr/local/lib -L/opt/local/lib -L/usr/lib
LIBS    = -lcrypto

SRCS = $(wildcard *.c)
SRCS_O = $(SRCS:.c=.o)
SRCS_O_ND = $(subst ./,,$(SRCS_O))

OBJ = $(SRCS_O_ND)
CSRC= $(wildcard *.c)

test: $(OBJ) test.o
	$(LD) $(LDFLAGS) $(LIBPATH) -o $@ $^ $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCPATH) -c $<

clean:
	rm *.o test;
