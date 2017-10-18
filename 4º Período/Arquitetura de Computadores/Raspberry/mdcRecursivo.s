.global _start
_start:
	MOV R1, #30 	@ Numero A
	MOV R2, #40	@ Numero B
	BAL _mdc
_mdc:
	CMP R2, #0 	@ Se $R2==0
	BEQ _end	@ Retorna A
_modulus:
	CMP R1, R2	@ Se R1 < R2
	BLT _invert	@ Faz MDC(b, a%b)
	SUB R1, R1, R2  @ $R1=$R1-$R2
	BAL _modulus
_invert:
	MOV R3, R1	@ $R3<-$R1
	MOV R1, R2	@ $R1<-$R2
	MOV R2, R3	@ $R2<-$R3
	BAL _mdc
_end:
	MOV R0, R1	@ Retorna A
	MOV R7, #1	@ Encerra
	SWI 0

