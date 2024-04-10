//
// main.c
// Struct_Practice
//
// Created by Victor Zerefos on 10/04/24.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
//Estrutura Livro
typedef struct _livro{
char titulo[100];
unsigned int numeroPaginas;
float preco;
} Livro;
//Estrutura Aluno
typedef struct _aluno {
char nome[100];
unsigned int idade;
Livro *livro_fav;
} Aluno;
// cria livro
Livro *create_livro(const char *titulo, unsigned int numeroPaginas, float preco)
{
Livro *livro = calloc(1, sizeof(Livro));
strcpy(livro->titulo, titulo);
livro->numeroPaginas = numeroPaginas;
livro->preco = preco;
return livro ;
}
// imprime livro
void display_livro(const Livro *livro){
printf("Titulo: %s\n", livro->titulo);
printf("Paginas: %d\n", livro->numeroPaginas);
printf("Preço: R$%.2f\n", livro->preco);
puts("");
}
// faz a cópia de um livro
Livro *copy_livro(const Livro *livro){
return create_livro(livro->titulo, livro->numeroPaginas, livro->preco);
}
void update_livro(Livro *livro_ref, float novoPreco){
livro_ref->preco = novoPreco;
}
//desaloca livro da memoria
void deallocate_livro(Livro **livro_ref){
Livro *livro = *livro_ref;
free(livro);
*livro_ref = NULL;
}
// cria aluno
Aluno *create_aluno(const char *nome, unsigned int idade, const Livro
*livro_fav){
Aluno *aluno = calloc(1, sizeof(Aluno));
strcpy(aluno->nome, nome);
aluno->idade = idade;
aluno->livro_fav = copy_livro(livro_fav);
return aluno;
}
// imprimi aluno
void display_aluno(const Aluno *aluno){
printf("Nome: %s\n", aluno->nome);
printf("Idade: %d\n", aluno->idade);
puts("-------------------------");
printf("Livro Favorito do %s\n", aluno->nome);
puts("-------------------------");
display_livro(aluno->livro_fav);
}
// desaloca aluno
void deallocate_aluno(Aluno **aluno_ref){
Aluno *aluno = *aluno_ref;
deallocate_livro(&aluno->livro_fav);
free(aluno);
*aluno_ref = NULL;
}
// Bloco de execução MAIN
int main(int argc, const char * argv[]) {
Livro *lord_of_the_ring = create_livro("Lord Of The Ring", 280, 129);
display_livro(lord_of_the_ring);
update_livro(lord_of_the_ring, 500);
Aluno *bob = create_aluno("Bob", 30, lord_of_the_ring);
display_aluno(bob);
deallocate_livro(&lord_of_the_ring);
deallocate_aluno(&bob);
return 0;
}
