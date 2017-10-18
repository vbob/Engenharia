/*Este programa multiplica dois numeros*/

.global _start
_start:
MOV R1, #30
MOV R2, #2
MUL R1, R2, R3
_exit:
MOV R7, #1
SWI 0