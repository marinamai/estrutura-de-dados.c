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

Carro *createCarro(char *marca, char *modelo, int ano, float preço){
    Carro *carro = calloc (1, sizeof(Carro));
    strcpy (carro ->marca, marca);
    strcpy (carro ->modelo, modelo);
    carro -> ano = ano;
    carro -> preço = preço;
    return carro;
}

void liberarCarro( Carro *carro){
    free (carro);
}

void infoCarro(Carro *carro){ 
    printf("Marca: %s\n", carro ->marca);
    printf("Modelo: %s\n", carro ->modelo);
    printf("Ano: %d\n", carro ->ano);
    printf("Preço: %.2f\n", carro ->preço);
    puts("#####################")
}

float calcularPreçoMedio(Carro **carros, int numCarros){
    float soma_preços = 0;
    for(int i=0; < numCarros; i++){
        soma_preços += carros[i] -> preço;
    }
    return soma_preços / numCarros;
}

int main(){
    Carro *carro1 = createCarro ("Volkswagen", "Nissan", 2020, 50000);
    Carro *carro2 = createCarro ("Audi", "BMW", 2019, 450000);
    Carro *carro3 = createCarro ("Chevrolet", "Ferrari", 2018, 3000000);

    infoCarro(carro1);
    infoCarro(carro2);
    infoCarro(carro3);

    Carro *carros[3] - {carro1, carro2, carro3};
    float preço_medio = calcularPreçoMedio(carros, 3);
    printf ("Preço médio dos carros citados: %.2f\n", preço_medio);

    liberarCarro(carro1);
    liberarCarro(carro2);
    liberarCarro(carro3);

    return 0;
}
