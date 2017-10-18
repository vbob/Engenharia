.data	
	cache: .word 0	@ Esta parte indica o nome da variável
					@ que receberá o valor salvo em memória

.global _start
_start:
	ldr r4, =cache	@ Ele vai falar que $R4 terá o endereço em memória que vx vai adicionar
	mov r5, #2		@ Este será o número que vx salvará em memória
	str r5, [r4]	@ Estou passando para o endereço salvo em R4 o valor de R5

_imprimir:
	mov r0, #1
	ldr r1, =cache	@ Ou seja, o valor que você adicionou em memória antes
	mov r2, #5		@ Aquele negócio de dizer o tamanho
	swi 0

_encerra:
	mov r7, #1		@ Comandos básicos de encerramento
	swi 0