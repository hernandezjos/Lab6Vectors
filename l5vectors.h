/*************************************
* @author Joey Hernandez
* @date 10/6/2026
* @file l5vectors.h
* compile: gcc l5interface.c l5vectors.c -o vectors
*
*************************************/

typedef struct Vec {
    char name;
    double ValX;
    double ValY;
    double ValZ;
} Vec;

Vec addVect(char inName, double inX, double inY, double inZ);
Vec vecAdd(Vec vecA, Vec vecB);
Vec vecSub(Vec vecA, Vec vecB);
Vec vecMult(Vec vecA, double coeff);

int storeVec(Vec newVec);
int findVec(char name, Vec *result);
int getVecAt(int index, Vec *result);
void clear(void);


