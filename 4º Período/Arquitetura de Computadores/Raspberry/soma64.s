/*Este programa soma dois numeros grandes*/

.global _start
_start:
MOV  R2, #0xFFFFFFFF	@Menor parte do numero 1
MOV  R3, #0x1		    @Maior parte do numero 1
MOV  R4, #0XFFFFFFF	    @Menor parte do numero 2
MOV  R5, #0xFF		    @Maior parte do numero 2
ADDS R0, R2, R4		    @Adicionando menores partes, usando flags
ADCS R1, R3, R5		    @Adicionando com flag carry on
_exit:
MOV  R7,#1
SWI  0
