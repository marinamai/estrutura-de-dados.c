//Crie uma struct chamada `Funcionario` com os campos: nome, idade, cargo e salário.
//- Implemente funções para alocar memória para um novo funcionário, liberar a memória quando
//não for mais necessária, aumentar o salário de um funcionário específico e exibir os detalhes de
//todos os funcionários.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CHAR 100
// definição da struct
typedef struct _funcionario{
char nome[MAX_CHAR];
int idade;
char cargo[MAX_CHAR];
float salário;
}Funcionario;
Funcionario *createFuncionario(char *nome, int idade, char *cargo, float
salario){
Funcionario *funcionario = calloc(1, sizeof(Funcionario));
strcpy(funcionario->nome, nome);
funcionario->idade = idade;
funcionario->salário = salario;
strcpy(funcionario->cargo, cargo);
return funcionario;
}
void deselocaFuncionario(Funcionario **funcionario_ref){
Funcionario *funcionario = *funcionario_ref;
free(funcionario);
funcionario_ref = NULL;
}
float aumentarSalario(Funcionario *funcionario){
funcionario->salário += funcionario->salário * 0.5;
return funcionario->salário;
}
void infoFuncionario(Funcionario **funcionarios, int qntFuncionarios){
puts("Lista de funcionarios");
for (int i = 0 ; i < qntFuncionarios; i++) {
printf("Nome: %s\n", funcionarios[i]->nome);
printf("Idade: %d\n", funcionarios[i]->idade);
printf("Gargo: %s\n", funcionarios[i]->cargo);
printf("Salario: %.2f\n", funcionarios[i]->salário);
puts("#######################");
}
}
//executa o programa
int main(int argc, const char * argv[]) {
Funcionario *f1 = createFuncionario("Paul", 34, "Mobile Dev", 10000);
Funcionario *f2 = createFuncionario("Macneil", 28, "Web Full Stack Dev",
3000);
aumentarSalario(f2);
Funcionario *funcionarios[] = {f1,f2};
int qntFuncionarios = sizeof(funcionarios) / sizeof(funcionarios[0]);
infoFuncionario(funcionarios, qntFuncionarios);
deselocaFuncionario(&f1);
deselocaFuncionario(&f2);
return 0;
}
