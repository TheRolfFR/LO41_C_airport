#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-msc30-c"
//
// Created by TheRolf on 15/05/2020.
//

#ifndef LO41_PROJET_ALEATOIRE_H
#define LO41_PROJET_ALEATOIRE_H

#include <stdlib.h>
#include <math.h>
#include <time.h>

void initAleatoire() {
    srand(time(NULL));
}

float aleatoireFloatRange(float min, float max, uint precision) {
    if(min == 0) {
        return rand()%((int) floorf(max)) + (rand()%(10*precision))/(10.0*precision);
    } else {
        return (max-min) + aleatoireFloatRange(0, max-min, precision);
    }
}

float aleatoireFloat(uint precision) {
    return rand() + (rand()%(10*precision))/(10.0*precision);
}

int aleatoireEntierRange(int min, int max) {
    return min + rand()%(max-min+1);
}

int aleatoireEntierMaxExclu(int maxexclu) {
    return rand()%maxexclu;
}

#endif //LO41_PROJET_ALEATOIRE_H

#pragma clang diagnostic pop