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
