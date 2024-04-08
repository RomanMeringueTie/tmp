all: mt_lib.a

mt_lib.a: mt*.o
	ar rcs sc_lib.a mt*.o

mt*.o: mt*.c
	gcc -c -I ~/architecture/include/ mt*.c

.PHONY: clean

clean: *.a *.o
	rm *.o
	rm *.a