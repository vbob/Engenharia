.data	
	cache: .word 0	@ Esta parte indica o nome da vari�vel
					@ que receber� o valor salvo em mem�ria

.global _start
_start:
	ldr r4, =cache	@ Ele vai falar que $R4 ter� o endere�o em mem�ria que vx vai adicionar
	mov r5, #2		@ Este ser� o n�mero que vx salvar� em mem�ria
	str r5, [r4]	@ Estou passando para o endere�o salvo em R4 o valor de R5

_imprimir:
	mov r0, #1
	ldr r1, =cache	@ Ou seja, o valor que voc� adicionou em mem�ria antes
	mov r2, #5		@ Aquele neg�cio de dizer o tamanho
	swi 0

_encerra:
	mov r7, #1		@ Comandos b�sicos de encerramento
	swi 0