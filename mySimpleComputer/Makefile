all: /home/roman/architecture/console/pr01

/home/roman/architecture/console/pr01: main.c sc_lib.a
	gcc -g -Wall -I /home/roman/architecture/include/ -o /home/roman/architecture/console/pr01 main.c sc_lib.a

sc_lib.a: sc*.o print*.o
	ar rcs sc_lib.a sc*.o print*.o

print*.o: print*.c
	gcc -g -c -I /home/roman/architecture/include/ print*.c

sc*.o: sc*.c
	gcc -g -c -I /home/roman/architecture/include/ sc*.c

.PHONY: clean

clean: sc_lib.a sc*.o print*.o
	rm sc*.o
	rm print*.o
	rm sc_lib.a
	rm /home/roman/architecture/console/pr01

.PHONY: run

run: /home/roman/architecture/console/pr01
	./../console/pr01