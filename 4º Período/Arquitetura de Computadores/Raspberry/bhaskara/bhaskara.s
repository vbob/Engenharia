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
    LDR     R1, =buffer
    MOV     R2, #0x30
    SWI     0
    @ convert n2 to bin and save in R9
    MOV     R10, #1
    BAL     convertAsciiToBin

.global _readn3
_readn3:
    MOV     R9, R0

    @ ask n3
    MOV     R7, #4
    MOV     R0, #1
    LDR     R1, =askn3
    LDR     R2, =askn3Len
    SWI     0
    @ read n3
    MOV     R7, #3
    MOV     R0, #0
    LDR     R1, =buffer
    MOV     R2, #0x30
    SWI     0
    @ convert n3 to bin and save in R9
    MOV     R10, #2
    BAL     convertAsciiToBin

.global _doMath
_doMath:
    MOV     R10, R0
    @ R8 = A, R9, = B, R10 = C 
    @ R6 = B^2
    MOV     R7, R9
    MUL     R6, R7, R9
    @ R7 = 4AC
    MOV     R7, #4
    MUL     R5, R7, R8  @ R5 = 4*A 
    MOV     R7, R5
    MUL     R7, R5, R10 @ R5*=C
    @ R0 = B^2 - 4AC
    SUB     R0, R6, R7
    @ if negative delta, jump
    CMP     R0, #0
    BLT     _raizNegativa
    @ R11 = DELTA
    MOV     R11, R0
    @ R12 = -B 
    RSB     R12, R9, #0
    @ R6 = 2A
    MOV     R0, #2
    MUL     R6, R0, R8
    MOV     R0, #1
    MOV     R1, #0

@ R1 = sqrt(delta) -> parte positiva (Método de Pell), subtração de números ímpares
_calcDeltaSqrt:
    CMP     R11, R0
    BLT     _preCalcX1
    SUB     R11, R11, R0
    ADD     R1, #1
    ADD     R0, #2
    BAL     _calcDeltaSqrt

_preCalcX1:
    @ R2 = 0, X1; R2 = 1, X2;
    MOV     R2, #0
    @ R3 IS NEGATIVE FLAG FOR NUMERATOR 
    MOV     R3, #0
    @ R11 = SQRT(DELTA)
    MOV     R11, R1
    @ Initialize counter for division
    MOV     R1, #0
    @ R0 = -B + SQRT(DELTA)
    ADD     R0, R12, R11
    CMP     R6, #0
    BLLT     _negativeDenominator
    CMP     R0, #0
    BLT     _negativeNumerator
    BAL     _calcX1

_calcX1: @ [-B + SQRT(DELTA)] / 2A
    @ R0 = numerator, R6 = denominator
    @ R1 = counter
    CMP     R0, R6
    BLT     _prePrintX1
    ADD     R1, #1
    SUB     R0, R0, R6
    BAL     _calcX1

_prePrintX1:
    MOV     R2, #3
    MOV     R0, R1
    CMP     R3, #1
    BEQ     _negativeNumerator
    BAL     _printX1

_printX1:
    MOV     R5, R0
    MOV     R3, #0
    MOV     R2, #1
    MOV     R7, #4
    MOV     R0, #0
    LDR     R1, =printRoot
    LDR     R2, =printRootLen
    SWI     0
    MOV     R0, R5
    @ R2 = 0, X1; R2 = 1, X2;
    MOV     R9, #1
    BAL     printR0

.global _preCalcX2
_preCalcX2:
    @ R3 IS NEGATIVE FLAG FOR NUMERATOR 
    MOV     R3, #0
    @ Initialize counter for division
    MOV     R1, #0
    @ R0 = -B - SQRT(DELTA)
    SUB     R0, R12, R11
    CMP     R6, #0
    BLLT     _negativeDenominator
    CMP     R0, #0
    BLT     _negativeNumerator
    BAL     _calcX2

_calcX2: @ [-B + SQRT(DELTA)] / 2A
    @ R0 = numerator, R6 = denominator
    @ R1 = counter
    CMP     R0, R6
    BLT     _prePrintX2
    ADD     R1, #1
    SUB     R0, R0, R6
    BAL     _calcX2

_prePrintX2:
    MOV     R2, #4
    MOV     R0, R1
    CMP     R3, #1
    BEQ     _negativeNumerator
    BAL     _printX2

_printX2:
    MOV     R5, R0
    MOV     R7, #4
    MOV     R0, #0
    LDR     R1, =printRoot
    LDR     R2, =printRootLen
    SWI     0
    MOV     R0, R5
    MOV     R9, #4
    BAL     printR0

_negativeNumerator: @ Invert R0
    MOV     R3, #1
    RSB     R0, R0, #0
    CMP     R2, #0
    BEQ     _calcX1
    CMP     R2, #1
    BEQ     _calcX2
    CMP     R2, #3
    BEQ     _printX1
    CMP     R2, #4
    BEQ     _printX2

_negativeDenominator: @ Invert R6
    MOV     R3, #1
    RSB     R6, R6, #0
    mov     pc, lr

_raizNegativa:
    MOV     R7, #4
    MOV     R0, #0
    LDR     R1, =negativeDelta
    LDR     R2, =negativeDeltaLen
    BAL     _end

.global _terminate
_terminate:
    MOV     R7, #4
    MOV     R0, #0
    LDR     R1, =newLine
    LDR     R2, =newLineLen
    SWI     0

    MOV     R7, #1
    SWI     0

.section .data
programInfo:
    .asciz "Este programa calcula a parte inteira de raizes de f(x) = Ax^2 + Bx + C usando a fórmula de Bhaskara\n"
programInfoLen =.-programInfo
askn1:
    .asciz "Digite o coeficiente A: "
askn1Len =.-askn1
askn2:
    .asciz "Digite o coeficiente B: "
askn2Len =.-askn2
askn3:
    .asciz "Digite o coeficiente C: "
askn3Len =.-askn3
negativeDelta:
    .asciz "Delta Negativo. Este programa calcula somente a parte inteira das raízes.\n"
negativeDeltaLen =.-negativeDelta
printRoot:
    .asciz "\nf(x) = 0 para: x = "
printRootLen =.-printRoot
newLine:
    .asciz "\n"
newLineLen =.-newLine
.section .bss
    .comm  buffer, 48