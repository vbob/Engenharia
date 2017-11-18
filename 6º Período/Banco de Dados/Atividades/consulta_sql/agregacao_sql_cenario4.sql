-- Atividade 1: 
-- Somar os totais de cada compra e comparar com os. 
-- Resultado: id_compra, some: compra_produto vl_total_produto
SELECT compra.id_compra AS "ID da Compra", SUM(compra_produto.valor_total_produto) AS "Valor Total da Compra"
FROM compra_produto, compra
WHERE compra_produto.id_compra = compra.id_compra
GROUP BY compra.id_compra
ORDER BY compra.id_compra


-- Atividade 2:
-- Somar os totais de compra por cliente
SELECT cliente.nome AS "Nome do Cliente", SUM(compra.valor_total) AS "Total Gasto na Loja"
FROM cliente, compra
WHERE compra.id_cliente = cliente.id_cliente
GROUP BY cliente.id_cliente
ORDER BY cliente.nome


-- Atividade 3:
-- Média de Vendas de Cada Produto
SELECT produto.marca AS "Produto", produto.valor_unitario AS "Valor Unitário", AVG(compra_produto.quantidade) as "Média de Vendas"
FROM produto, compra_produto
WHERE produto.id_produto = compra_produto.id_produto
GROUP BY produto.id_produto
ORDER BY produto.id_produto

-- Atividade 4:	
-- Média de Valor das Compras por Cliente
SELECT cliente.nome AS "Nome do Cliente", AVG(compra.valor_total) AS "Total Gasto na Loja"
FROM cliente, compra
WHERE compra.id_cliente = cliente.id_cliente
GROUP BY cliente.id_cliente
ORDER BY cliente.nome

-- Atividade 5:
-- Valor Médio das Compras
SELECT AVG(compra.valor_total) AS "Valor Médio das Compras"
FROM compra
