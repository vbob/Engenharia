/* Print Hello World*/
.text
.global _start

_start:
MOV R7, #4		@ Write system call
MOV R0, #1		@ File (stdout)
LDR R1, =message
MOV R2, #14		@ Message lenght
SVC #0
MOV R7, #1		@ Exit system call
MOV R0, #0		@ Return code
SVC #0
.data
message:
.ascii "Hello, World!\n"
