/*************************
* @author Joey H
* @file l5vectors.c
* @date 10/6/2026
* update: added git access
*************************/

#include <stdio.h>
#include <string.h>

typedef struct Vec {
    char name;
    double ValX;
    double ValY;
    double ValZ;
} Vec;

Vec vectors[10];

Vec addVect (char inName, double inX, double inY, double inZ){
    Vec newVec;

    newVec.name = inName;
    newVec.ValX = inX;
    newVec.ValY = inY;
    newVec.ValZ = inZ;

    return newVec;
}

Vec vecAdd (Vec vecA, Vec vecB) {
    Vec answer;

 answer.ValX = vecA.ValX + vecB.ValX;
 answer.ValY = vecA.ValY + vecB.ValY;
 answer.ValZ = vecA.ValZ + vecB.ValZ;
    printf("ans = %f  %f  %f\n", answer.ValX, answer.ValY, answer.ValZ);
    return answer;
}

Vec vecSub (Vec vecA, Vec vecB) {
    Vec answer;

 answer.ValX = vecA.ValX - vecB.ValX;
 answer.ValY = vecA.ValY - vecB.ValY;
 answer.ValZ = vecA.ValZ - vecB.ValZ;
    printf("ans = %f  %f  %f\n", answer.ValX, answer.ValY, answer.ValZ);
    return answer;
}

Vec vecMult (Vec vecA, double in) {
    Vec answer;

 answer.ValX = vecA.ValX * in;
 answer.ValY = vecA.ValY * in;
 answer.ValZ = vecA.ValZ * in;
    printf("ans = %f  %f  %f\n", answer.ValX, answer.ValY, answer.ValZ);
    return answer;
}

void clear() {
    for (int i = 0; i < 10; i++) {
        vectors[i].name = '\0';
        vectors[i].ValX = 0.0;
        vectors[i].ValY = 0.0;
        vectors[i].ValZ = 0.0;
    }
}

void list() {
    for (int i = 0; i < 10; i++) {
        if (vectors[i].name != '\0') {
        printf("%c = %f  %f  %f", vectors[i].name, vectors[i].ValX, vectors[i].ValY, vectors[i].ValZ);
        }
    }

}

Vec findVec(char *name) {
    for (int i = 0; i < 10; i++) {
        if (vectors[i].name == *name)  
        {
            printf("%c = %f  %f  %f", vectors[i].name, vectors[i].ValX, vectors[i].ValY, vectors[i].ValZ);
            Vec copyVec = vectors[i];
            return copyVec;
            i = 11;
        }
    }
}