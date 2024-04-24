//Crie uma struct chamada `Produto` com os campos: nome, preço e quantidade em estoque.
//- Implemente funções para alocar memória para um novo produto, liberar a memória quando
//não for mais necessária, atualizar o estoque de um produto específico e exibir os detalhes de
//todos os produtos.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _produto{
    char nome[50]; 
    int QuantidadeEstoqye;
    float preço;
}Produto;
