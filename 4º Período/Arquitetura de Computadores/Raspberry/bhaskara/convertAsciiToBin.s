.section .text
.global convertAsciiToBin
convertAsciiToBin:
    LDRB    r2, [r1]
    MOV     r3, #0

pushDigits:
    STMFD   sp!, {r2}
    ADD     r3, r3, #1
    LDRB    r2, [r1, #1]!
    CMP     r2, #0xA
    BEQ     convDigits
    BNE     pushDigits

convDigits:
    MOV r4, #1
    MOV r0, #0
    MOV r6, #0

jumpBack:
    LDMFD  sp!, {r2}
    CMP	    r2, #0x2D
    BEQ     negativo
    CMP     r2, #0x30
    BLT     error
    cmp     r2, #0x39
    bgt     error
    sub     r2, r2, #0x30
    mul     r2, r4, r2
    add     r0, r0, r2
    add     r6, r6, #1
    cmp     r6, r3
    beq     exit
    mov     r5, r4, lsl #3
    add     r4, r5, r4, lsl #1
    bal     jumpBack

negativo:
    rsb    r0, r0, #0
    bal    exit

error:
    mov r7, #4
    mov r0, #1
    ldr r1, =message
    ldr r2, =messageLen
    swi 0

    mov r7, #1
    swi 0

exit:
    cmp r10, #0
    beq _readn2
    cmp r10, #1
    beq _readn3
    bal _doMath

.section .data
    message:
        .asciz "\nValor inválido. Digite somente números\n"
    messageLen =.-message
