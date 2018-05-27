-- Consulta 1
SELECT cliente.nome, compra.valor_total, compra.dt_compra, compra.nome_caixa
FROM cliente, compra
WHERE compra.id_cliente = cliente.id_cliente
	AND compra.valor_total > 30
ORDER BY cliente.nome, compra.valor_total;

-- Consulta que exibe o nome do cliente,d o caixa e a forma de pagamento 
-- Ordenado pela Data da Compra e Valor Total
SELECT compra.dt_compra, compra.valor_total, cliente.nome, compra.nome_caixa, forma_pagto.descricao
FROM cliente, compra, forma_pagto
WHERE compra.id_cliente = cliente.id_cliente
	AND compra.id_forma_pagto = forma_pagto.id_forma_pagto
ORDER BY compra.dt_compra, compra.valor_total

-- Desenvolva uma consulta SQL que traga os produtos de cada compra.
-- O relatório deve ser ordenado por dta da compra, valor total e nome do produto
-- Devem constar também o valor unitário, quantidade comprada e valor total de produto
SELECT compra.dt_compra, compra_produto.valor_total_produto, produto.marca, produto.descricao, produto.valor_unitario, compra_produto.quantidade
FROM compra, produto, compra_produto
WHERE compra_produto.id_compra = compra.id_compra
	AND compra_produto.id_produto = produto.id_produto
ORDER BY compra.dt_compra, compra_produto.valor_total_produto, produto.marca


-- Liste os produtos que constam em alguma compra, possuem quantidade em estoque maior que 10 unidades
-- e foram vendidas mais de 2 unidades por compra. No resultado liste: nome_produto, qte_estoque, dt_compra e qtde_vendida
SELECT produto.marca, quantidade_estoque, dt_compra, compra_produto.quantidade
FROM produto, compra, compra_produto
WHERE produto.quantidade_estoque > 10 
    AND compra_produto.quantidade > 2
    AND compra_produto.id_produto = produto.id_produto
    AND compra.id_compra = compra_produto.id_compra
ORDER BY produto.marca, quantidade_estoque, dt_compra

/* 
 * Tarefa
 *
 * Desenvolva duas consultas SQL e seus enunciados. 
 * Uma dessas consultas deve utilizar todas as tabelas 
 *
 */


-- Liste a forma de pagamento utilizada pelas compras com valor superior a 20 reais
-- No resultado, liste: Nome do Cliente, Data da Compra, o Valor da Compra e a forma de pagamento
-- Ordenar pelo valor da compra

SELECT compra.valor_total, compra.forma_pgto, compra.dt_compra, cliente.nome
FROM compra, cliente, forma_pagto
WHERE compra.valor_total > 20
 	AND compra.id_cliente = cliente.id_cliente
	AND compra.id_forma_pagto = forma_pagto.id_forma.pagto
ORDER BY compra.valor_total
