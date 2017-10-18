soma: convertAsciiToBin.o 
soma: soma.o
	ld convertAsciiToBin.o soma.o -o soma
convertAsciiToBin.o: convertAsciiToBin.s 
	as convertAsciiToBin.s -o convertAsciiToBin.o
soma.o: soma.s 
	as soma.s -o soma.o
clean:
	rm *.o
debug:
	ld convertAsciiToBin.o soma.o -o soma -g
