.global _start
_start:
MOV R1, #2
MOV R2, #5
CMP R1, R2
BEQ igual
diferente:
MOV R0, #1
B   fim
igual:
MOV R0, #0
B   fim
fim:
MOV R7, #1
SWI 0
