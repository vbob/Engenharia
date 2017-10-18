.data
	var1: 		.word 3
	var2:		.word 5

.global _start
_start:
	ldr r1, add_var1	@ r1 = &var1
	ldr r1, [r1]		@ r1 = *r1

	ldr r2, add_var2	@ r2 = &var2
	ldr r2, [r2]		@ r2 = *r2

	add r0, r1, r2
	mov r7, #1
	swi 0

add_var1: .word var1
add_var2: .word var2
