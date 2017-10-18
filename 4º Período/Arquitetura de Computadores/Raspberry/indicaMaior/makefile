indicaMaior: indicaMaior.o 
indicaMaior: convertAsciiToBin.o
	ld indicaMaior.o convertAsciiToBin.o -o indicaMaior
indicaMaior.o:
	as indicaMaior.s -o indicaMaior.o 
convertAsciiToBin.o: 
	as convertAsciiToBin.s -o convertAsciiToBin.o
clean:
	rm *.o 
debug: indicaMaior.o
	ld indicaMaior.o convertAsciiToBin.o -o indicaMaior -g