.global fatorialR0
fatorialR0:
	MOV R1, R0
	CMP R1, #1
	BGT doFatorial
	CMP R1, #0
	BGE fatorialZero
	MOV R7, #1
	SWI 1
doFatorial:
	SUB R1, R1, #1
	MUL R2, R0, R1
	MOV R0, R2
	CMP R1, #1
	BEQ jump
	BAL doFatorial
fatorialZero:
	MOV R0, #1
	BAL jump
jump:
    @ R3 -> FLAG! #0 = N!, #1 = P!, #2 = N-P!
	CMP     R3, #0
    BEQ     _pFactorial
    CMP     R3, #1
    BEQ     _nMpFactorial
    CMP     R3, #2
    BEQ     _doMath
