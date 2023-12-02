#include "bignumber.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validateBigNumber(char *elements) {
    int size = strlen(elements);
    for (int i = 0; i < size; i++) {
        if (elements[i] == '\0') continue;
        if (elements[i] == '\n') continue;

        if ((elements[i] < 48 || elements[i] > 57) && elements[i] != 45) {
            return 0;
        }
    }

    return 1;
}

void copyElementsToBigNumber(BigNumber a, char *elements) {
    for (int i = 0; i < a->size; i++) {
        if (elements[i] == '-') continue;

        if (a->isNegative) {
            a->elements[i - 1] = elements[i] - '0';
        } else {
            a->elements[i] = elements[i] - '0';
        }
    }
}

void reverseBigNumber(BigNumber a) {
    for (int i = 0; i < a->size / 2; i++) {
        int temp = a->elements[i];
        a->elements[i] = a->elements[a->size - i - 1];
        a->elements[a->size - i - 1] = temp;
    }
}

BigNumber getBigNumber() {
    BigNumber a = malloc(sizeof(BigNumber));
    char *elements = malloc(MAX_SIZE);

    if (a == NULL || elements == NULL) {
        printf("Erro: Limite de memoria excedido!");
        exit(1);
    }

    do {
        printf("Digite o numero:\n");
        printf("Exemplo de formatacao - positivo: 54658\n");
        printf("Exemplo de formatacao - negativo: -145793\n");
        fgets(elements, MAX_SIZE, stdin);
        if (!validateBigNumber(elements)) {
            system("clear");
            printf("***Digite um numero nos formatos validos...***\n");
        }
    } while (!validateBigNumber(elements));

    a->size = strlen(elements) - 1;
    if (elements[a->size - 1] == '\n') {
        a->size = a->size - 1;
    }
    elements = realloc(elements, strlen(elements) * sizeof(char));
    a->elements = calloc(a->size + 1, sizeof(int));
    if (a->elements == NULL) {
        printf("Erro: Limite de memoria excedido!");
        exit(1);
    }
    if (elements[0] == '-') a->isNegative = 1;

    copyElementsToBigNumber(a, elements);
    free(elements);

    system("clear");
    return a;
}

void printBigNumber(BigNumber a) {
    for (int i = 0; i < a->size + 1; i++) {
        printf("%d", a->elements[i]);
    }
}

void sumBigNumber(BigNumber a, BigNumber b) {
    reverseBigNumber(a);
    reverseBigNumber(b);
    int size = a->size > b->size ? a->size : b->size;
    char d = a->size > b->size ? 'a' : 'b';
    int x = 0;

    for (int i = 0; i < size + 1; i++) {
        int res;

        if (i > (a->size > b->size ? b->size : a->size)) {
            if (d == 'a') {
                res = a->elements[i] + 0 + x;
            } else {
                res = 0 + b->elements[i] + x;
            }
        } else {
            res = a->elements[i] + b->elements[i] + x;
        }
        if (res > 9) {
            if (d == 'a') {
                a->elements[i] = res % 10;
            } else {
                b->elements[i] = res % 10;
            }
            x = 1;
        } else {
            if (d == 'a') {
                a->elements[i] = res;
            } else {
                b->elements[i] = res;
            }
            x = 0;
        }
    }
    reverseBigNumber(a);
    reverseBigNumber(b);

    if (d == 'a') printBigNumber(a);
    else printBigNumber(b);
}