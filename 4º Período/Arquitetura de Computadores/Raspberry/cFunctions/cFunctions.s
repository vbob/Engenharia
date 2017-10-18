.data                                           @ Salva as mensagens a serem impressas em uma 'variável'
.balign 4
pergunta: .asciz "Qual seu número preferido? "  @ Pergunta inicial

.balign 4
resposta: .asciz "%d é um número legal\n"       @ Perecba que usa o padrão de printf 

.balign 4
padraoLeitura: .asciz "%d"                      @ Perecba que usa o padrão de scanf 

.balign 4
numero: .word 0                                 @ Salva o número que o usuário digitar

.balign 4
lr_bu: .word 0                                  @ Ponteiro de execução

.text 
.global main                                    @ Para usar C é necessário que a função golbal principal se chame main
.func main                                      @ E também é necessário ser indicada como .func

main:
     LDR R1, addr_lr_bu                         @ Salva o ponteiro de execução na memória
     STR lr, [R1]                               @ pois o compilador gerará uma _start padrão antes compilar este programa
    
     LDR R0, addr_question                      @ Define em R0 o que deve ser escrito
     BL printf                                  @ Chama printf pra imprimir R0

     LDR R0, addr_pattern                       @ Define o padrão do que ser lido ("%d") em R0
     LDR R1, addr_number                        @ Define em R1 onde deve ser salvo o valor lido
     BL scanf                                   @ Chama printf para ler

     LDR R0, addr_message                       @ Coloca em R0 a mensagem a ser escrita
     LDR R1, addr_number                        @ Como a mensagem vai ter uma variável ("%d"), é passado em R1 o número a ser escrito
     LDR R1, [R1]                               @ E tem que passado o número puro, não o endereço
     BL printf                                  @ Chama printf pra imrimir R0 ("%d ..."), R1

     LDR lr, addr_lr_bu                         @ O programa gerará uma função pra terminar padrão
     LDR lr, [lr]                               @ Então é necessário retornar para a posição da função pra terminar
     BX lr 

addr_question: .word question                   @ Define os endereços de memória onde estão salvos os textos
addr_message: .word message
addr_pattern: .word pattern
addr_number: .word number
addr_lr_bu: .word lr_bu

.global printf                                  @ Indica as funções C que serão usadas
.global scanf


