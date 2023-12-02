#ifndef BIGNUMBER_H
#define BIGNUMBER_H

// provisório
#define MAX_SIZE 5000

typedef struct {
    int *elements;
    unsigned int isNegative;
    unsigned int size;
} *BigNumber;

BigNumber getBigNumber();

void sumBigNumber(BigNumber a, BigNumber c);

#endif
