#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CHAR 100
// definição da struct aluno
typedef struct _aluno{
char nome[MAX_CHAR];
int idade;
int matricula;
float media;
}Aluno;
// aloca(cria) aluno na memoria
Aluno *create(char *nome, int idade, int matricula, float media){
Aluno *a = calloc(1, sizeof(Aluno));
if (a == NULL) {
puts("Erro ao alocar memória para o aluno.\n");
exit(EXIT_FAILURE);
}
strcpy(a->nome, nome);
a->idade = idade;
a->matricula = matricula;
a->media = media;
return a;
}
//desaloca(destroi) aluno da memoria
void desalocarAluno(Aluno **aluno_ref){
Aluno *a = *aluno_ref;
free(a);
*aluno_ref = NULL;
}
//imprime aluno no console
void infoAluno(Aluno *aluno){
printf("Nome: %s\n", aluno->nome);
printf("Idade: %d\n", aluno->idade);
printf("Matricula: %d\n", aluno->matricula);
printf("Media: %.2f\n", aluno->media);
puts("\n");
}
//calcula a media da turma
float calcularMediaTurma(Aluno **alunos, int quantidadeAlunos){
float soma = 0.0;
for (int i = 0; i < quantidadeAlunos; i++) {
soma += alunos[i]->media;
}
return soma / quantidadeAlunos;
}
//executa o programa
int main(int argc, const char * argv[]) {
Aluno *aluno1 = create("Victor", 34, 1234, 8.5);
Aluno *aluno2 = create("Aghata", 28, 4321, 9.0);
infoAluno(aluno1);
infoAluno(aluno2);
Aluno *turmaAluno[] = {aluno1,aluno2};
int quantidadeAlunos = sizeof(turmaAluno) / sizeof(turmaAluno[0]);
float mediaTurma = calcularMediaTurma(turmaAluno, quantidadeAlunos);
printf("Media da turma: %.2f\n", mediaTurma);
desalocarAluno(&aluno1);
desalocarAluno(&aluno2);
return 0;
}// fim
