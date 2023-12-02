#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bignumber.h"

int main(void) {
    int casosDeTeste;

    do {
        printf("Digite o total de casos de teste:\n");
        scanf("%d", &casosDeTeste);
        getchar();
        if (casosDeTeste < 1) {
            system("clear");
            printf("O total de casos de teste deve no minimo um...\n");
        }
    } while (casosDeTeste < 1);

    system("clear");
    for (int teste = 0; teste < casosDeTeste; teste++) {
        printf("Teste %d:\n", teste + 1);

        BigNumber a = getBigNumber();
        BigNumber b = getBigNumber();
        char operation;
        
        do {
            printf("Digite uma operacao:\n");
            printf("Soma: +, Subtracao: -, Multiplicacao: *\n");
            scanf("%c", &operation);
            getchar();

            switch (operation) {
                case '+':
                    system("clear");
                    printBigNumber(a);
                    printf("  +\n");
                    printBigNumber(b);
                    printf("-------------\n");
                    sumBigNumber(a, b);
                    printf("Aperte qualquer tecla para continuar...\n");
                    getchar();
                    break;
                case '-':
                    // subtract(a, b);
                    break;
                case '*':
                    // multiply(a, b);
                    break;
                default:
                    system("clear");
                    printf("***Insira uma operacao valida!***\n");
                    break;
            }
        } while(operation != '+' && operation != '-' && operation != '*');
        system("clear");
        // destroyBigNumber(a);
        // destroyBigNumber(b);
    }
    return 0;
}
