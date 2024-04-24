//Crie uma struct chamada `Funcionario` com os campos: nome, idade, cargo e salário.
//- Implemente funções para alocar memória para um novo funcionário, liberar a memória quando
//não for mais necessária, aumentar o salário de um funcionário específico e exibir os detalhes de
//todos os funcionários.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _funcionario{
    char nome[50]; 
    char cargo[50];
    int idade;
    float salario;
}Funcionario;

Funcionario *create(char nome, char cargo, int idade, double salario){
    Funcionario *a = calloc(1, sizeof(Funcionario));
    if (a == NULL) {
        puts(" Erro ao localizar memoria do funcionario.\n");
        exit(EXIT_FAILURE);
    }
    strcpy(a->nome,nome);
    a-> cargo = cargo;
    a-> idade = idade;
    a-> salario = salario;
return a;
}




