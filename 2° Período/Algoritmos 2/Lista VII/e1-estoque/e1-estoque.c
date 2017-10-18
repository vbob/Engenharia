#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIMPAR system("clear");
#define ESPERAR printf("\n\nPressione qualquer tecla para continuar..."); getchar(); getchar();

typedef struct {
    int codigo;
    char nome[50];
    int quantidade;
    float precou;
    int qvendido;
} RegProduto;

typedef struct {
    int codigo;
    char cliente[50];
    int codproduto;
    int quantidade;
    float precot;
} RegVenda;

typedef struct {
    int cvendas;
    int cprodutos;
} RegCodigos;

void incluirprod(int *codigo);
void incluirvenda();
void alterarprod(int cod, int op);
void alterarvenda(int cod, int op);
void relatorios();
int verificaDuplicados(char registro, int codigo);
void imprimirRelatorio (char registro);

void main() {
    int selecao;
    selecao = 0;
    do {
        RegCodigos codigo;
        FILE *binarioC;
        FILE *binarioCN;
        binarioC = fopen("codigos.bin", "r+");
        binarioCN = fopen(".codigos.bin", "a");
        int cVendas, cProdutos;
        if (binarioC == NULL) {
             binarioC = fopen("codigos.bin", "a");
             cVendas = 1;
             cProdutos = 1;
             codigo.cvendas = cVendas;
             codigo.cprodutos = cProdutos; 
             fwrite(&codigo,sizeof(codigo),1,binarioC);
        }
        else {
            fread(&codigo,sizeof(codigo),1,binarioC);
            cVendas = codigo.cvendas;
            cProdutos = codigo.cprodutos;
        }
        int codproduto;
        LIMPAR;
        printf("********************************\n");
        printf("1 - Incluir produto\n");
        printf("2 - Informar venda\n");
        printf("3 - Alterar ou excluir produto\n");
        printf("4 - Alterar ou excluir venda\n");
        printf("5 - Relatorios\n");
        printf("6 - Sair\n");
        printf("********************************\n");
        printf("\nInsira a opcao desejada: ");
        scanf("%d", &selecao);
        switch (selecao) {
            case 1: LIMPAR
                    incluirprod(&cProdutos); 
                    ESPERAR
                    break;
            case 2: LIMPAR
                    incluirvenda(&cVendas);
                    ESPERAR
                    break;
            case 3: LIMPAR
                    printf("\nDigite o codigo do produto a ser alterado: ");
                    scanf("%i", &codproduto);
                    while (verificaDuplicados('p', codproduto) == 0) {
                        system("clear");
                        printf("\nPRODUTO NAO CADASTRADO");
                        printf("\nPARA SAIR DIGITE -1");
                        printf("\nDigite novamente o codigo do produto a ser alterado: ");
                        scanf("%i", &codproduto);
                        if (codproduto == -1) {
                            return;
                        }
                    }
                    alterarprod(codproduto, 0);  
                    LIMPAR  
                    ESPERAR
                    break;
            case 4: LIMPAR
                    printf("\nDigite o codigo da venda a ser alterada: ");
                    scanf("%i", &codproduto);
                    while (verificaDuplicados('v', codproduto) == 0) {
                        system("clear");
                        printf("\nVENDA NAO CADASTRADA");
                        printf("\nPARA SAIR DIGITE -1");
                        printf("\nDigite novamente o codigo da venda a ser alterada: ");
                        scanf("%i", &codproduto);
                        if (codproduto == -1) {
                            return;
                        }
                    }
                    alterarvenda(codproduto, 0);    
                    LIMPAR
                    ESPERAR
                    break;
            case 5: LIMPAR
                    relatorios();
                    ESPERAR           
            default: break;
        }   
        codigo.cvendas = cVendas;
        codigo.cprodutos = cProdutos; 
        fwrite(&codigo,sizeof(codigo),1,binarioCN);
        fclose(binarioC);
        fclose(binarioCN);
        system("rm codigos.bin");
        system("mv .codigos.bin codigos.bin");
    } while (selecao != 6);
}

void incluirprod(int *codigo) {
    FILE *binarioP;
    RegProduto produto;
    binarioP = fopen("produtos.bin", "a");
    if (binarioP == NULL) {
        char selecao[2];
        do {
            LIMPAR
            printf("\nCadastro de produtos corrompido");
            printf("\nDeseja apagar o banco de dados atual? (S/N): ");
            scanf(" %s", selecao);
            switch (selecao[0]) {
                case 's': system("rm produtos.bin");
                          incluirprod(codigo);
                          return;             
                case 'S': system("rm produtos.bin");
                          incluirprod(codigo);
                          return;                             
                case 'n': return;           
                case 'N': return;  
                default: break;    
            } 
        } while (selecao[0] =! 'n' || selecao[0] != 's');
    }
    else {
        produto.codigo = *codigo;
        *codigo = produto.codigo+1;
        
        printf ("\nDigite o nome do produto: ");
        scanf(" %[^\n]s]", produto.nome);
        
        printf ("\nDigite a quantidade em estoque do produto: ");
        scanf("%d", &produto.quantidade);
        while (produto.quantidade <= 0) {
             system("clear");
             printf("\nQUANTIDADE INFERIOR A 1");
             printf("\nPARA SAIR DIGITE -1");
             printf ("\nDigite a quantidade em estoque do produto: ");
             scanf("%d", &produto.quantidade);
             if (produto.quantidade == -1) {
                return;
             }
        } 
        
        printf ("\nDigite o preco unitario do produto: R$");
        scanf("%f", &produto.precou);
        
        produto.qvendido = 0;
        
        fwrite(&produto,sizeof(produto),1,binarioP);
        
        printf("\nProduto cadastrado com sucesso");
    }
    fclose(binarioP);         
}

void incluirvenda(int *codigo) {
    FILE *binarioV;
    binarioV = fopen("vendas.bin", "a");
    RegVenda venda;
    if (binarioV == NULL) {
        char selecao[2];
        do {
            LIMPAR
            printf("\nCadastro de vendas corrompido");
            printf("\nDeseja apagar o banco de dados atual? (S/N): ");
            scanf(" %s", selecao);
            switch (selecao[0]) {
                case 's': system("rm vendas.bin");
                          incluirvenda(codigo);
                          return;             
                case 'S': system("rm vendas.bin");
                          incluirvenda(codigo);
                          return;                             
                case 'n': return;           
                case 'N': return;
                default: break;      
            } 
        } while (selecao[0] =! 'n' || selecao[0] != 's');
    }
    else {
        venda.codigo = *codigo;
        *codigo = venda.codigo+1;
        
        printf("\nDigite o codigo do produto vendido: ");
        scanf("%i", &venda.codproduto);
        
        while (verificaDuplicados('p', venda.codproduto) == 0) {
             system("clear");
             printf("\nPRODUTO NAO CADASTRADO");
             printf("\nPARA SAIR DIGITE -1");
             printf("\nDigite novamente o codigo do produto vendido: ");
             scanf("%i", &venda.codproduto);
             if (venda.codproduto == -1) {
                return;
             }
        } 
        
        printf ("\nDigite o nome do cliente: ");
        scanf(" %[^\n]s]", venda.cliente);
        
        printf ("\nDigite a quantidade vendida: ");
        scanf("%d", &venda.quantidade);
        
         while (venda.quantidade <= 0) {
             system("clear");
             printf("\nQUANTIDADE INFERIOR A 1");
             printf("\nPARA SAIR DIGITE -1");
             printf("\nDigite novamente a quantidade vendida: ");
             scanf("%i", &venda.quantidade);
             if (venda.quantidade == -1) {
                return;
             if (verificaDuplicados('q', venda.codproduto) < venda.quantidade) {
                    system("clear");
                    printf("\nQUANTIDADE VENDIDA SUPERIOR A EM ESTOQUE");
                    printf("\nDigite novamente a quantidade vendida: ");
                    scanf("%i", &venda.quantidade);
                }
             }
        } 
        
        
               
        alterarprod(venda.codproduto, (1000+venda.quantidade));
        
        venda.precot = verificaDuplicados('r', venda.codproduto)*venda.quantidade;
        
        fwrite(&venda,sizeof(venda),1,binarioV);
        
        printf("\n Venda cadastrada com sucesso");
    }
    fclose(binarioV);         
}

void alterarprod(int codigo, int op) {
    if (op == 0) {
        while (op != 1 && op != 2) {
            system("clear");
            printf("********************************\n");
            printf("Código do produto selecionado: %d\n\n", codigo);
            printf("1 - Editar\n");
            printf("2 - Apagar\n");
            printf("3 - Voltar\n");
            printf("********************************\n");
            printf("\nInsira a opcao desejada: ");
            scanf("%d", &op);
            system("clear");
            if (op == 3) 
                return;
            if (op == 2) {
                if (verificaDuplicados('w', codigo) == 1) {
                       system("clear");
                       printf("O produto possui vendas cadastradas e não pode ser excluiído\n");
                }
            }
        }
    }
               
    if (op == 1 || op == 2) {
        RegProduto produto;
        FILE *binarioP;
        FILE *binarioPN;
        binarioP = fopen("produtos.bin", "r+");
        binarioPN = fopen(".produtos.bin", "a");
        while(!feof(binarioP)) {
            fread(&produto,sizeof(produto),1,binarioP);
            if (feof(binarioP))
                break;
            if (produto.codigo != codigo) 
                fwrite(&produto,sizeof(produto),1,binarioPN);
            else {
                if (op == 1) {
                    incluirprod(&codigo);     
                    codigo = -1;      
                }    
            }
        }       
        fclose(binarioP);
        fclose(binarioPN);
        system("rm produtos.bin");
        system("mv .produtos.bin produtos.bin");

        printf("Operacao concluida com sucesso\n");
    }
    
    if ((op > 1000 && op < 2000) || (op < -1000 && op > -2000)) {
             RegProduto produto;
             FILE *binarioP;
             FILE *binarioPN;
             binarioP = fopen("produtos.bin", "r+");
             binarioPN = fopen(".produtos.bin", "a");
             while(!feof(binarioP)) {
                fread(&produto,sizeof(produto),1,binarioP);
                if (feof(binarioP))
                    break;
                if (op > 0) {
                    if (produto.codigo != codigo) 
                        fwrite(&produto,sizeof(produto),1,binarioPN);
                    else {
                        produto.qvendido = op - 1000;
                        produto.quantidade = produto.quantidade-(op-1000);
                        fwrite(&produto,sizeof(produto),1,binarioPN);                    
                    }
                }
                else {
                    if (produto.codigo != codigo) 
                        fwrite(&produto,sizeof(produto),1,binarioPN);
                    else {
                        produto.qvendido = produto.qvendido - (op + 1000);
                        fwrite(&produto,sizeof(produto),1,binarioPN);                    
                    }
                }
            }       
            fclose(binarioP);
            fclose(binarioPN);
            system("rm produtos.bin");
            system("mv .produtos.bin produtos.bin");
    }
    }


void alterarvenda(int codigo, int op) {
        if (op == 0) {
        while (op != 1 && op != 2) {
            system("clear");
            printf("********************************\n");
            printf("Código da venda selecionada: %d\n\n", codigo);
            printf("1 - Editar\n");
            printf("2 - Apagar\n");
            printf("3 - Voltar\n");
            printf("********************************\n");
            printf("\nInsira a opcao desejada: ");
            scanf("%d", &op);
            system("clear");
            if (op == 3) 
                return;
        }
    }
               
    if (op == 1 || op == 2) {
        RegVenda venda;
        FILE *binarioV;
        FILE *binarioVN;
        binarioV = fopen("vendas.bin", "r+");
        binarioVN = fopen(".vendas.bin", "a");
        while(!feof(binarioV)) {
            fread(&venda,sizeof(venda),1,binarioV);
            if (feof(binarioV))
                break;
            if (venda.codigo != codigo) 
                fwrite(&venda,sizeof(venda),1,binarioVN);
            else {
                alterarprod(venda.codproduto, (-1000-venda.quantidade));
                if (op == 1) {
                    incluirvenda(&codigo);     
                    codigo = -1;          
                }
            }       
        fclose(binarioV);
        fclose(binarioVN);
        system("rm vendas.bin");
        system("mv .vendas.bin vendas.bin");
        system("clear");
        system("clear");
        system("clear");
        printf("Operacao concluida com sucesso\n");
        }      
    }
}
void relatorios() {
    int selecao;
    do {
        printf("********************************\n");
        printf("1 - Listagem de produtos\n");
        printf("2 - Listagem de vendas\n");
        printf("3 - Voltar\n");
        printf("********************************\n");
        printf("\nInsira a opcao desejada: ");
        scanf("%d", &selecao);
        system("clear");
        switch (selecao) {
            case 1: imprimirRelatorio('p');
                    selecao = 3;
                    break;
            case 2: imprimirRelatorio('v');
                    selecao = 3;
                    
            default: break;
        } 
    } while (selecao != 3);
}

void imprimirRelatorio (char registro) {
     if (registro == 'p') {
            RegProduto produto;
             FILE *binarioP;
             binarioP = fopen("produtos.bin", "r");
             while(!feof(binarioP)) {
                fread(&produto,sizeof(produto),1,binarioP);
                if (feof(binarioP))
                    break;
                printf("\nCódigo: %i\n", produto.codigo);
                printf("\tNome: %s\n", produto.nome);
                printf("\tQtde. em Estoque: %i\n", produto.quantidade);
                printf("\tPreco unitario: R$%.2f\n", produto.precou);
                printf("\tQtde. Vendida: %i\n", produto.qvendido);                
                }
        } 
        if (registro == 'v') {
            RegVenda venda;
             FILE *binarioV;
             binarioV = fopen("vendas.bin", "r");
             while(!feof(binarioV)) {
                fread(&venda,sizeof(venda),1,binarioV);
                if (feof(binarioV))
                    break;
                printf("\nCódigo: %i\n", venda.codigo);
                printf("\tCódigo do Produto Vendido: %i\n", venda.codproduto);
                printf("\tNome do Cliente: %s\n", venda.cliente);
                printf("\tQtde. Vendida: %i\n", venda.quantidade);
                printf("\tPreco Total da Venda: R$%.2f\n", venda.precot);              
                }
        } 
                 
}     

int verificaDuplicados (char registro, int codigo) {
    if (registro == 'p') {
        RegProduto produto;
             FILE *binarioP;
             binarioP = fopen("produtos.bin", "r");
             while(!feof(binarioP)) {
                fread(&produto,sizeof(produto),1,binarioP);
                if (feof(binarioP))
                    break;
                if (produto.codigo == codigo) {
                    fclose(binarioP); 
                    return 1;
                    break;
                }
             }          
        return 0;
    } 
    if (registro == 'q') {
        RegProduto produto;
             FILE *binarioP;
             binarioP = fopen("produtos.bin", "r");
             while(!feof(binarioP)) {
                fread(&produto,sizeof(produto),1,binarioP);
                if (produto.codigo == codigo) {
                    fclose(binarioP); 
                    return produto.quantidade;
                    break;
                }
             }          
    }       
     if (registro == 'r') {
        RegProduto produto;
             FILE *binarioP;
             binarioP = fopen("produtos.bin", "r");
             while(!feof(binarioP)) {
                fread(&produto,sizeof(produto),1,binarioP);
                if (produto.codigo == codigo) {
                    fclose(binarioP); 
                    return produto.precou;
                    break;
                }
             }          
    }  
     if (registro == 'v') {
        RegVenda venda;
        FILE *binarioV;
        binarioV = fopen("vendas.bin", "r");
        while(!feof(binarioV)) {
            fread(&venda,sizeof(venda),1,binarioV);
            if (feof(binarioV))
                break;
            if (venda.codigo == codigo) {
                fclose(binarioV); 
                return 1;
                break;
            }
        }          
        return 0;
    }
    if (registro == 'w') {
        RegVenda venda;
        FILE *binarioV;
        binarioV = fopen("vendas.bin", "r");
        while(!feof(binarioV)) {
            fread(&venda,sizeof(venda),1,binarioV);
            if (feof(binarioV))
                break;
            if (venda.codproduto == codigo) {
                fclose(binarioV); 
                return 1;
                break;
            }
        }          
        return 0;
    }      
}
