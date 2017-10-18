.data
	num1: .word 0
	num2: .word 0

.global _start
_start:
	ldr r1, =num1
	mov r3, #3
	str r3, [r1]

	ldr r2, =num2
	mov r4, #4
	str r4, [r2]

	ldr r1, =num1
	ldr r1, [r1]
	ldr r2, =num2
	ldr r2, [r2]
	@ add r0, r1, r2
	ldr r0, num1
	mov r7, #1
	swi 0
