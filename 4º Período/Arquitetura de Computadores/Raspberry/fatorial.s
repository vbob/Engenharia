.global _start
_start:
	MOV R1, #5
	MOV R0, R1
	CMP R1, #1
	BGT _fatorial
	CMP R1, #0
	BGE _fatorialz
	MOV R7, #1
	SWI 1
_fatorial:
	SUB R1, R1, #1
	MUL R2, R0, R1
	MOV R0, R2
	CMP R1, #1
	BEQ _end
	BAL _fatorial
_fatorialzu:
	MOV R0, #1
	BAL _end
_end:
	MOV R7, #1
	SWI 0
