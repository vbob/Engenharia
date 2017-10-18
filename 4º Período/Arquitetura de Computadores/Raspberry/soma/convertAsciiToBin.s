.section .text
.global convertAsciiToBin
convertAsciiToBin:
    ldrb    r2, [r1]
    mov     r3, #0

pushDigits:
    stmfd   sp!, {r2}
    add     r3, r3, #1
    ldrb    r2, [r1, #1]!
    cmp     r2, #0xA
    beq     convDigits
    bne     pushDigits

convDigits:
    mov r4, #1
    mov r0, #0
    mov r6, #0

jumpBack:
    ldmfd   sp!, {r2}
    cmp	    r2, #0x2D
    beq     negativo
    cmp     r2, #0x30
    blt     error
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
    bal _terminate

.section .data
    message:
        .asciz "\nValor inválido. Digite somente números\n"
    messageLen =.-message
