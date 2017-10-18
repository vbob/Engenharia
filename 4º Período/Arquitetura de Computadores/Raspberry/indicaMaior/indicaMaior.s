.section .text
.global _start
_start:
    @ print program programInfo
    MOV     R7, #4
    MOV     R0, #1
    LDR     R1, =programInfo
    LDR     R2, =programInfoLen
    SWI     0
    @ ask n1
    MOV     R7, #4
    MOV     R0, #1
    LDR     R1, =askn1
    LDR     R2, =askn1Len
    SWI     0
    @ read n1
    MOV     R7, #3
    MOV     R0, #0
    LDR     R1, =bufferN1
    MOV     R2, #0x30
    SWI     0
    @ convert n1 to bin and save in R8
    MOV     R10, #0
    BAL     convertAsciiToBin

.global _readn2
_readn2:
    MOV     R8, R0
    @ ask n2
    MOV     R7, #4
    MOV     R0, #1
    LDR     R1, =askn2
    LDR     R2, =askn2Len
    SWI     0
    @ read n2
    MOV     R7, #3
    MOV     R0, #0
    LDR     R1, =bufferN2
    MOV     R2, #0x30
    SWI     0
    @ convert n2 to bin and save in R9
    MOV     R10, #1
    BAL     convertAsciiToBin

.global _print
_print:
    MOV     R9, R0

    MOV     R7, #4
    MOV     R0, #1
    LDR     R1, =newLine
    LDR     R2, =newLineLen
    SWI     0

    @ imprime resultado
    MOV     R7, #4
    MOV     R0, #1
    LDR     R1, =resultado
    LDR     R2, =resultadoLen
    SWI     0

    @ compara
    CMP     R8, R9
    BGT     _printN1
    BAL     _printN2

_printN1:
    MOV     R7, #4
    MOV     R0, #1
    LDR     R1, =bufferN1
    LDR     R2, =5
    SWI     0
    BAL     _terminate

_printN2:
    MOV     R7, #4
    MOV     R0, #1
    LDR     R1, =bufferN2
    LDR     R2, =3
    SWI     0
    BAL     _terminate

_terminate:
    MOV     R7, #1
    SWI     0


.section .data
programInfo:
    .asciz "Este programa compara dois números e indica o maior\n"
programInfoLen =.-programInfo
askn1:
    .asciz "\nInsira o primeiro número: "
askn1Len =.-askn1
askn2:
    .asciz "Insira o segundo número: "
askn2Len =.-askn2
resultado: 
    .asciz "O maior número é: "
resultadoLen =.-resultado
newLine:
    .asciz "\n"
newLineLen =.-newLine

.section .bss
    .comm bufferN1, 48
    .comm bufferN2, 48