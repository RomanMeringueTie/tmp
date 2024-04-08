all: myTerm/mt_lib.a mySimpleComputer/sc_lib.a myBigChars/bc_lib.a myTerm/mt_lib.a myReadKey/rk_lib.a console/concole

console/concole: console/concole.c myTerm/mt_lib.a mySimpleComputer/sc_lib.a myBigChars/bc_lib.a myTerm/mt_lib.a myReadKey/rk_lib.a
	gcc -g -I include/ -o console/concole console/concole.c myTerm/mt_lib.a mySimpleComputer/sc_lib.a myBigChars/bc_lib.a myTerm/mt_lib.a myReadKey/rk_lib.a

console/print*.o: console/print*.c
	gcc -g -c -Iinclude/ console/print*.c
	cp *.o console
	rm *.o

myReadKey/rk_lib.a: myReadKey/rk*.o
	ar rcs myReadKey/rk_lib.a myReadKey/rk*.o

myReadKey/rk*.o: myReadKey/rk*.c
	gcc -g -c -Iinclude/ myReadKey/rk*.c mySimpleComputer/sc*.c
	cp *.o myReadKey
	rm *.o

myBigChars/bc_lib.a: myBigChars/bc*.o
	ar rcs myBigChars/bc_lib.a myBigChars/bc*.o

myBigChars/bc*.o: myBigChars/bc*.c
	gcc -g -c -Iinclude/ myBigChars/bc*.c
	cp *.o myBigChars
	rm *.o

myTerm/mt_lib.a: myTerm/*.o
	ar rcs myTerm/mt_lib.a myTerm/*.o

mySimpleComputer/sc_lib.a: mySimpleComputer/sc*.o console/print*.o
	ar rcs mySimpleComputer/sc_lib.a mySimpleComputer/sc*.o console/print*.o

myTerm/*.o: myTerm/*.c
	gcc -g -c -Iinclude/ myTerm/*.c
	cp *.o myTerm
	rm *.o

mySimpleComputer/sc*.o: mySimpleComputer/sc*.c
	gcc -g -c -Iinclude/ mySimpleComputer/sc*.c
	cp *.o mySimpleComputer
	rm *.o

clean:
	rm mySimpleComputer/*.o
	rm mySimpleComputer/*.a
	rm myTerm/*.o
	rm myTerm/*.a
	rm console/*.o
	rm myBigChars/*.o
	rm myBigChars/*.a
	rm console/concole

.PHONY: run

run:
	./console/concole