/*************************************
* @author Joey Hernandez
* @date 10/6/2026
* @file l5vectors.c
* compile: gcc l5interface.c l5vectors.c -o vectors
*
*************************************/

#include "l5vectors.h"

Vec vectors[10];

Vec addVect(char inName, double inX, double inY, double inZ) {
    Vec newVec;

    newVec.name = inName;
    newVec.ValX = inX;
    newVec.ValY = inY;
    newVec.ValZ = inZ;

    return newVec;
}

Vec vecAdd(Vec vecA, Vec vecB) {
    Vec answer;

    answer.name = '\0';
    answer.ValX = vecA.ValX + vecB.ValX;
    answer.ValY = vecA.ValY + vecB.ValY;
    answer.ValZ = vecA.ValZ + vecB.ValZ;

    return answer;
}

Vec vecSub(Vec vecA, Vec vecB) {
    Vec answer;

    answer.name = '\0';
    answer.ValX = vecA.ValX - vecB.ValX;
    answer.ValY = vecA.ValY - vecB.ValY;
    answer.ValZ = vecA.ValZ - vecB.ValZ;

    return answer;
}

Vec vecMult(Vec vecA, double coeff) {
    Vec answer;

    answer.name = '\0';
    answer.ValX = vecA.ValX * coeff;
    answer.ValY = vecA.ValY * coeff;
    answer.ValZ = vecA.ValZ * coeff;

    return answer;
}

int storeVec(Vec newVec) {
    // if there is no name given dont store it
    if (newVec.name == '\0') {
        return 0;
    }

    // if name you stored exists already then replace the old one
    for (int i = 0; i < 10; i++) {
        if (vectors[i].name == newVec.name) {
            vectors[i] = newVec;
            return 1;
        }
    }

    for (int i = 0; i < 10; i++) {
        if (vectors[i].name == '\0') {
            vectors[i] = newVec;
            return 1;
        }
    }
    // return 0 if storage full
    return 0;  
}

int findVec(char name, Vec *result) {
    for (int i = 0; i < 10; i++) {
        if (vectors[i].name == name) {
            *result = vectors[i];
            return 1;
        }
    }

    return 0;
}

// gets vector but checks if its valid at that index
int getVecAt(int index, Vec *result) {
    if (index < 0 || index >= 10 || vectors[index].name == '\0') {
        return 0;
    }

    *result = vectors[index];
    return 1;
}

void clear(void) {
    for (int i = 0; i < 10; i++) {
        vectors[i].name = '\0';
        vectors[i].ValX = 0.0;
        vectors[i].ValY = 0.0;
        vectors[i].ValZ = 0.0;
    }
}
