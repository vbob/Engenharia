CREATE TABLE forma_pagto (
	id_forma_pagto INTEGER PRIMARY KEY,
	descricao VARCHAR(20)
)

CREATE TABLE cliente (
	id_cliente INTEGER PRIMARY KEY,
	nome_cliente VARCHAR(100),
	cpf CHAR(14),
	endereco_cliente VARCHAR(200),
	telefone VARCHAR(16)
)

CREATE TABLE compra (
	id_compra INTEGER PRIMARY KEY,
	dt_compra DATE,
	valor_total NUMERIC(7,2),
	nome_caixa VARCHAR(20),
	id_cliente INTEGER,
	id_forma_pagto INTEGER,
	FOREIGN KEY(id_cliente) REFERENCES cliente (id_cliente),
	FOREIGN KEY(id_forma_pagto) REFERENCES forma_pagto (id_forma_pagto)
)

CREATE TABLE produto (
	id_produto INTEGER PRIMARY KEY,
	marca VARCHAR(20),
	descricao VARCHAR(50),
	valor_unitario NUMERIC(5,2),
	quantidade_estoque INTEGER
)

CREATE TABLE compra_produto (
	PRIMARY KEY(id_compra,id_produto),
	id_compra INTEGER,
	id_produto INTEGER,
	quantidade INTEGER,
	valor_total_produto NUMERIC(6,2),
	FOREIGN KEY(id_compra) REFERENCES compra (id_compra),
	FOREIGN KEY(id_produto) REFERENCES
)
