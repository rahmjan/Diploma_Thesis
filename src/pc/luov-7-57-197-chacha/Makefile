CC=gcc
CFLAGS=-I$(HOME)/XKCP/bin/generic64/ # point this and the one below to wherever the keccak code package is located
LFLAGS=-L$(HOME)/XKCP/bin/generic64/ -lkeccak -lcrypto

IMPLEMENTATION_SOURCE = chacha.c Column.c F7Field.c F79Field.c F47Field.c F61Field.c LUOV.c LinearAlgebra.c buffer.c prng.c rng.c intermediateValues.c
IMPLEMENTATION_HEADERS= chacha.h Column.h F7Field.h F79Field.c F47Field.h F61Field.h LUOV.h LinearAlgebra.h buffer.h prng.h rng.h intermediateValues.h api.h parameters.h 

test: $(IMPLEMENTATION_SOURCE) $(IMPLEMENTATION_HEADERS) test.c
	gcc -o test $(IMPLEMENTATION_SOURCE) test.c $(CFLAGS) $(LFLAGS) -std=c99 -g 

clean:
	rm -f test PQCgenKAT_sign  profile profile.txt fast *.req *.rsp >/dev/null
