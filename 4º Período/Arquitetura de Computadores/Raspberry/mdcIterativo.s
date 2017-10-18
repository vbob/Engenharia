.global _start
@ $R0 receberá o resultado
@ $R1 será o número A e $R2 será o número B
@ $R3 será R
_start:
	MOV R1, #15 	@ Número A
	MOV R2, #40	@ Número B
_cmpToEnd:
	CMP R2, #0	@ Se b==0, termine
	BEQ _end
	MOV R3, R1
	BAL _findR 	@ Senao ache R
_findR:
	CMP R3, R2	@ Se B < A
	BLT _changeMDC	@ Altera para MDC(B, R)
	SUB R3, R3, R2	@ A = A - B
	BAL _findR	@ Faça novamente
_changeMDC:
	MOV R1, R2
	MOV R2, R3
	BAL _cmpToEnd
_end:
	MOV R0, R1 	@ Copia a resposta para $R1
	MOV R7, #1	@ Encerra
	SWI 0
