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

.global _preCalcFactorial
_preCalcFactorial:
    @ N = R8, P = R9
    MOV     R9, R0

    @ R10 = N-P 
    SUB     R10, R8, R9
    CMP     R10, #0
    BLT     _nGreaterThanP

_nFactorial:
    @ R3 -> FLAG! #0 = N!, #1 = P!, #2 = N-P!
    MOV     R3, #0
    MOV     R0, R8
    BAL     fatorialR0

.global _pFactorial
_pFactorial:
    MOV     R8, R0
    MOV     R3, #1
    MOV     R0, R9
    BAL     fatorialR0

.global _nMpFactorial
_nMpFactorial:
    MOV     R9, R0
    MOV     R3, #2
    MOV     R0, R10
    BAL     fatorialR0

.global _doMath
_doMath:
    MOV     R10, R0
    @ NUMERATOR = R0, DENOMINATOR = R1, R3 = COUNTER
    MOV     R0, R8
    MOV     R1, R10
    MOV     R3, #0

_NOverNmP:
    CMP     R0, R1
    BLT     _preDivideByP
    SUB     R0, R0, R1
    ADD     R3, #1
    BAL     _NOverNmP

_preDivideByP:
    MOV     R0, R3
    MOV     R1, R9
    MOV     R3, #0

_DivideByP:
    CMP     R0, R1
    BLT     _print
    SUB     R0, R0, R1
    ADD     R3, #1
    BAL     _DivideByP

_print:
    MOV     R7, #4
    MOV     R0, #0
    LDR     R1, =printAnswer
    LDR     R2, =printAnswerLen
    SWI     0

    MOV     R0, R3
    MOV     R9, #4
    BAL     printR0

_nGreaterThanP:
    MOV     R7, #4
    MOV     R0, #1
    LDR     R1, =errorNGreater
    LDR     R2, =errorNGreaterLen
    SWI     0

   BAL      _terminate

.global _terminate
_terminate:
    MOV     R7, #4
    MOV     R0, #0
    LDR     R1, =newLine
    LDR     R2, =newLineLen
    SWI     0

    MOV     R7, #1
    SWI     0

programInfo:
    .asciz "Este programa calcula combinação simples de n elementos distintos tomados agrupados p a p\n"
programInfoLen =.-programInfo
askn1:
    .asciz "Digite o número de elementos (n): "
askn1Len =.-askn1
askn2:
    .asciz "Digite o tamanho do agrupamento (p): "
askn2Len =.-askn2
printAnswer:
    .asciz "\nC(n, p) = "
printAnswerLen =.-printAnswer
errorNGreater:
.asciz "\nERRO: p não pode ser maior do que n"
errorNGreaterLen =.-errorNGreater
newLine:
    .asciz "\n"
newLineLen =.-newLine
.section .bss
    .comm  buffer, 48