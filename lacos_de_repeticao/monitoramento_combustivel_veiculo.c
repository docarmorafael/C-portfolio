// Programa em C que faz o monitoramento do abastecimento de um veículo a cada viagem realizada.   
// Utiliza funções de consumo total, calcular média de consumo por viagem e contagem de viagens com
// valor de consumo superior a 50.
// Além disso, utiliza o laço de repetição For para percorrer o valor de consumo em cada uma das 10 viagens.
// Ao final, exibe um relatório com os dados de consumo total de combustível,
// consumo médio de combustível por viagem, viagem com maior consumo, maior quantidade combustível gasto na viagem e
// quantidade de viagens com consumo superior a 50 litros.

#include <stdio.h>

float consumoTotal(float valorConsumo[], int tamanho) {
    float total = 0;

    for (int i = 0; i < tamanho; i++) {
        total += valorConsumo[i];
    }

    return total;
}

float calcularMedia(float total, int tamanho) {
    return total / tamanho;
}

int contViagens(float valorConsumo[], int tamanho) {
    int cont = 0;

    for (int i = 0; i < tamanho; i++) {
        if (valorConsumo[i] > 50) {
            cont++;
        }
    }

    return cont;
}

int main() {

    printf("\n----- MONITORAMENTO DE ABASTECIMENTO -----\n");

    float valorConsumo[10];
    float quantTotal;
    float quantMedia;
    float maiorConsumo;
    int viagMaior = 0;
    int contTotal;

    for (int i = 10; i >= 1; i--) {

        printf("Informe a quantidade de litros consumidos por viagem: ");
        scanf("%f", &valorConsumo[i]);

        if (i == 0) {
            maiorConsumo = valorConsumo[i];
        } 
        else if (valorConsumo[i] > maiorConsumo) {
            maiorConsumo = valorConsumo[i];
            viagMaior = i;
        }
    }

    quantTotal = consumoTotal(valorConsumo, 10);
    quantMedia = calcularMedia(quantTotal, 10);
    contTotal = contViagens(valorConsumo, 10);

    
    printf("\n----- RELATÓRIO -----\n");

    printf("\nConsumo total de combustível: %.2f litros", quantTotal);
    printf("\nConsumo médio de combustível por viagem: %.2f litros", quantMedia);
    printf("\nViagem com maior consumo: %d", viagMaior + 1);
    printf("\nCombustível gasto na viagem: %.2f litros", maiorConsumo);
    printf("\nViagens com gasto superior a 50 litros: %d", contTotal);

    return 0;
}
