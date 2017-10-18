.data
	msg1: .ascii "Ola \n"
	len1= .-msg1

.text
.global _start
_start:
	mov r0, #1
	ldr r1, =msg1
	mov r2, #30
	mov r7, #4
	swi 0

	mov r7, #1
	swi 0
