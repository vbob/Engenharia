combinacao: convertAsciiToBin.o 
combinacao: printR0.o 
combinacao: fatorial.o
combinacao: combinacao.o
	ld convertAsciiToBin.o printR0.o combinacao.o fatorial.o -o combinacao
convertAsciiToBin.o: convertAsciiToBin.s 
	as convertAsciiToBin.s -o convertAsciiToBin.o 
printR0.o: printR0.s 
	as printR0.s -o printR0.o 
combinacao.o: combinacao.s 
	as combinacao.s -o combinacao.o 
fatorial.o: fatorial.s
	as fatorial.s -o fatorial.o
clean:
	rm *.o
debug: convertAsciiToBin.o 
debug: printR0.o 
debug: 
	ld convertAsciiToBin.o printR0.o combinacao.o fatorial.o -o combinacao -g