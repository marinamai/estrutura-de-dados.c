//Crie uma struct chamada `Carro` com os campos: marca, modelo, ano e preço.
//- Escreva funções para alocar memória para um novo carro, liberar a memória quando não for
//mais necessária, exibir os detalhes de um carro específico e calcular o preço médio dos carros casdastrados.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _carro{
    char marca [30]; 
    char modelo[30];
    int ano;
    float preço;
}Carro;
