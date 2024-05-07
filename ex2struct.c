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

//cria funcionario na memoria
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
//destroi funcionario da memoria
void desalocarFuncionario(Funcionario **funcionario_ref){
    Funcionario *a = *funcionario_ref;
    free(a);
    *aluno_ref =NULL;
}

//aumenta o salario
void aumentarSalario(Funcionario *funcionario, float aumento){
    funcionario->salario += aumento;
} 
//imprime funcionario no console
void infoFuncionario(Funcionario*funcionario){
    printf("Nome: %s\n", funcionario->nome);
    printf("Idade: %d\n", funcionario->idade);
    printf("Cargo: %s\n", funcionario->cargo);
    printf("Salário: %2f\n", funcionario->salario);
    puts("\n");
}
int main(){
//criar funcionario
    Funcionario *func1 = create("Maria", "Desenvolvedor", 30, 5000.0);
    Funcionario *func2 = create("Eduarda", "Junior", 10, 1000.0);
//exibir detalhe dos funcionarios
    printf("Detalhe dos funcionarios:\n");
    infoFuncionario(func1);
    infoFuncionario(func2);
//aumentarSalario
    aumentarSalario(func1, 1000.0);
//exibir detalhes dos funcionario atualizado
    printf("Novo salário do funcionário:\n");
    infoFuncionario(func1);

//liberar a memoria alocada p funcionarios
    desalocarFuncionario(&func1);
    desalocarFuncionario(&func2);
return 0;
}
