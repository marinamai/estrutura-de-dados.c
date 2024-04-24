//Crie uma struct chamada `Cliente` com os campos: nome, idade, endereço e número de telefone.
//- Implemente funções para alocar memória para um novo cliente, liberar a memória quando não
//for mais necessária, atualizar informações de um cliente e exibir os detalhes de todos os clientes.
//- Escreva um programa para testar suas funções.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _cliente{
    char nome[50]; 
    char endereço[50];
    int idade;
    int numero;
    int telefone;
}Cliente; 
