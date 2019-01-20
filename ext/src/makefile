all:
	gcc main.c ./pgmlib/lib/*.c -o main

shared:
	mkdir -p lib
	gcc -c -fpic ./pgmlib/lib/pgm.c
	gcc -shared -o lib/pgm.so pgm.o

clean:
	rm main pgm.o lib/pgm.so
