//Crie uma struct chamada `Produto` com os campos: nome, preço e quantidade em estoque.
//- Implemente funções para alocar memória para um novo produto, liberar a memória quando
//não for mais necessária, atualizar o estoque de um produto específico e exibir os detalhes de
//todos os produtos.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _produto{
    char nome[50]; 
    int estoque;
    float preço;
}Produto;

Produto *createProduto(char *nome, int estoque, float preço){
    Produto *produto = calloc (1, sizeof (Produto));
    strcpy (produto-> nome, nome);
    produto ->estoque = estoque;
    produto -> preço = preço;
return produto;
}

void deslocaProduto(Produto *produto){
    free (produto);
}

void aumentarEstoque (Produto *produto, int quantidade){
    produto -> estoque += quantidade;
}
void infoProduto(Produto *produto){
        printf("Nome: %s\n", produto->nome);
        printf("Estoque: %d\n", produto->estoque);
        printf("Preço: %.2f\n", produto->preço);
        puts("#####################");
    }
int main(){
    Produto *banana = createProduto ("Banana", 10, 6.99);
    Produto *uva = createProduto ("Uva", 20, 9.99);

    infoProduto(banana);
    infoProduto(uva);

    aumentarEstoque(banana, 3);
    aumentarEstoque(uva, 2);

    infoProduto(banana);
    infoProduto(uva);

    desalocarProduto(banana);
    desalocarProduto(uva);

    return 0;
}
