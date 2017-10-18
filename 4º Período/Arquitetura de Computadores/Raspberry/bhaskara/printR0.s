.global printR0
printR0:
    mov     r10, r0
    stmfd   sp!, {r4,r5,lr}
    cmp     r0, #0
    moveq   r0, #'0'
    bleq    printToScreen
    beq     conditions
    mov     r4, sp
    mov     r5, sp
    sub     sp, sp, #12
    rsblt   r0, r0, #0          
    movlt   lr, #1              
    movgt   lr, #0
    ldr     r1, =0x1999999a     

loop:   
    umull   r2, r3, r0, r1      
    sub     r2, r0, r3, lsl #3
    sub     r2, r2, r3, lsl #1  
    add     r2, r2, #'0'
    strb    r2, [r4, #-1]!
    movs    r0, r3
    bne     loop
    cmp     lr, #0
    movne   r0, #'-'
    blne    printToScreen

write: 
    ldrb    r0, [r4], #1
    bl      printToScreen
    cmp     r4, r5
    blt     write
    add     sp, sp, #12

done:
    ldmfd   sp!, {r4,r5,lr}
    mov     r0, #'\n'
    b       printToScreen

printToScreen:
    LDR     R1, =buffer
    STR     R0, [R1]

    MOV     R7, #4
    MOV     R0, #0
    LDR     R1, =buffer
    MOV     R2, #1
    SWI     0    

conditions:
    CMP     R10, #0
    BLT     invertR0
    CMP     R9, #1
    BEQ     _preCalcX2
    CMP     R9, #4
    BEQ     _terminate

invertR0:
    RSB     R0, R10, #0
    BAL     printR0

.section .bss
    .comm buffer, 48