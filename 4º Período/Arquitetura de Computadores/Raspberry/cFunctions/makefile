cFunctions: cFunctions.o 
	ld cFunctions.o -o cFunctions
cFunctions.o: cFunctions.s 
	as cFunctions.s -o cFunctions.o 
clean:
	rm *.o 
debug: cFunctions.o 
	ld cFunctions.o -o cFunctions -g
gcc: 
	gcc -o cFunctions cFunctions.s