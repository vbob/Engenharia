.data
	num1: 	.word 4
	num2: 	.word 5

.global _start
_start:
	LDR R1, =num1
	LDR R1, [R1]

	LDR R2, =num2
	LDR R2, [R2]

	ADD R0, R1, R2

	MOV R7, #1
	SWI 0
