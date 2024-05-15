//Crie uma struct chamada `Cliente` com os campos: nome, idade, endereço e número de telefone.
//- Implemente funções para alocar memória para um novo cliente, liberar a memória quando não
//for mais necessária, atualizar informações de um cliente e exibir os detalhes de todos os clientes.
//- Escreva um programa para testar suas funções.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[100];
    int idade;
    char endereco[100];
    char telefone[20];
} Cliente;

Cliente* criarCliente(const char* nome, int idade, const char* endereco, const char* telefone) {
    Cliente* cliente = (Cliente*)malloc(sizeof(Cliente));
    if (cliente != NULL) {
        strcpy(cliente->nome, nome);
        cliente->idade = idade;
        strcpy(cliente->endereco, endereco);
        strcpy(cliente->telefone, telefone);
    }
    return cliente;
}

void exibirCliente(const Cliente* cliente) {
    printf("Nome: %s\n", cliente->nome);
    printf("Idade: %d\n", cliente->idade);
    printf("CEP: %s\n", cliente->endereco);
    printf("Telefone: %s\n", cliente->telefone);
    printf("\n");
}

void liberarCliente(Cliente* cliente) {
    free(cliente);
}

int main() {
    int numClientes;
    printf("Quantos clientes deseja adicionar? ");
    scanf("%d", &numClientes);

    Cliente** clientes = (Cliente*)malloc(numClientes * sizeof(Cliente));
    if (clientes == NULL) {
        printf("Erro de alocacao de memoria.\n");
        return 1;
    }

    for (int i = 0; i < numClientes; i++) {
        char nome[100], endereco[100], telefone[20];
        int idade;

        printf("\nCliente %d\n", i + 1);
        printf("Digite o nome: ");
        scanf("%s", nome);

        printf("Digite a idade: ");
        scanf("%d", &idade);

        printf("Digite o endereco: ");
        scanf("%s", endereco);

        printf("Digite o telefone: ");
        scanf("%s", telefone);

        clientes[i] = criarCliente(nome, idade, endereco, telefone);
        if (clientes[i] == NULL) {
            printf("Erro de alocacao de memoria.\n");
            return 1;
        }
    }

    printf("\nDetalhes dos clientes:\n");
    for (int i = 0; i < numClientes; i++) {
        printf("\nCliente %d\n", i + 1);
        exibirCliente(clientes[i]);
    }

    for (int i = 0; i < numClientes; i++) {
        liberarCliente(clientes[i]);
    }
    free(clientes);

    return 0;
}
