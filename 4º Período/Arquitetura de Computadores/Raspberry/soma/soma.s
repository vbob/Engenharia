.section .text
.global _start
_start:
    @ ask n1
    MOV     R7, #4
    MOV     R0, #1
    LDR     R1, =askn1
    LDR     R2, =askn1Len
    SWI     0

    @ read n1
    MOV     R7, #3
    MOV     R0, #0
    LDR     R1, =buffer
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
    LDR     R1, =bufferA
    MOV     R2, #0x30
    SWI     0

    @ convert n2 to bin and save in R9
    MOV     R10, #1
    BAL     convertAsciiToBin

.global _terminate
_terminate:
    MOV     R9, R0
    ADD     R0, R8, R9
    MOV     R7, #1
    SWI     0

.section .data
askn1:
    .asciz "Digite o primeiro numero: "
askn1Len =.-askn1
askn2:
    .asciz "Digite o segundo numero: "
askn2Len =.-askn2

.section .bss
    .comm  buffer, 48
    .comm  bufferA, 48
