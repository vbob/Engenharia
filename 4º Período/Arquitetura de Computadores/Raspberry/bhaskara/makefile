bhaskara: convertAsciiToBin.o 
bhaskara: printR0.o 
bhaskara: bhaskara.o
	ld convertAsciiToBin.o printR0.o bhaskara.o -o bhaskara
convertAsciiToBin.o: convertAsciiToBin.s 
	as convertAsciiToBin.s -o convertAsciiToBin.o 
printR0.o: printR0.s 
	as printR0.s -o printR0.o 
bhaskara.o: bhaskara.s 
	as bhaskara.s -o bhaskara.o 
clean:
	rm *.o
debug: convertAsciiToBin.o 
debug: printR0.o 
debug: 
	ld convertAsciiToBin.o printR0.o bhaskara.o -o bhaskara -g