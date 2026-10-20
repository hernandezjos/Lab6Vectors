/*************************************
* @author Joey Hernandez
* @date 10/6/2026
* @file l5interface.c
* compile: gcc l5interface.c l5vectors.c -o vectors
*
*************************************/

#include <stdio.h>
#include <string.h>
#include "l5vectors.h"

// method to print vectors
void printVec(Vec vec) {
    printf("%c = %.2f  %.2f  %.2f\n",
           vec.name, vec.ValX, vec.ValY, vec.ValZ);
}

// check if a vector name is a valid 1 letter name
int validName(const char *word) {
    if (strlen(word) != 1) {
        return 0;
    }

    if ((word[0] >= 'a' && word[0] <= 'z') ||
        (word[0] >= 'A' && word[0] <= 'Z')) {
        return 1;
    }

    return 0;
}

// sscanf reads input
int readNumber(const char *word, double *value) {
    char extra;

    if (sscanf(word, "%lf%c", value, &extra) == 1) {
        return 1;
    }

    return 0;
}

// checking if the name is valid for either a new vector or for searching for an old one
int readStored(const char *word, Vec *vec) {
    if (!validName(word)) {
        printf("Invalid vector name: %s\n", word);
        return 0;
    }

    if (!findVec(word[0], vec)) {
        printf("Vector %c not found.\n", word[0]);
        return 0;
    }

    return 1;
}

// check which math func to use by checking the signs
int checkSign(const char *left, const char *op, const char *right, Vec *answer) {
    Vec vecA, vecB;
    double coeff;
    // add and subtract
    if (strcmp(op, "+") == 0 || strcmp(op, "-") == 0) {
        if (!readStored(left, &vecA) || !readStored(right, &vecB)) {
            return 0;
        }

        if (strcmp(op, "+") == 0) {
            *answer = vecAdd(vecA, vecB);
        }
        else {
            *answer = vecSub(vecA, vecB);
        }

        return 1;
    }
    // scalar multiplication
    else if (strcmp(op, "*") == 0) {
        if (validName(left) && readNumber(right, &coeff)) {
            if (!readStored(left, &vecA)) {
                return 0;
            }
            *answer = vecMult(vecA, coeff);
            return 1;
        }
        else if (readNumber(left, &coeff) && validName(right)) {
            if (!readStored(right, &vecA)) {
                return 0;
            }
            *answer = vecMult(vecA, coeff);
            return 1;
        }
    }

    printf("Invalid Input.\n");
    return 0;
}

void interface(void) {
    char line[256];
    char *token[8];
    int count;
    Vec answer;
    double x, y, z;

    while (1) {
        printf("minimat> ");
        fflush(stdout);

        if (!fgets(line, sizeof(line), stdin)) {
            break;
        }

        // check if input is too long
        if (!strchr(line, '\n') && !feof(stdin)) {
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF) { }
            printf("Invalid Input.\n");
            continue;
        }

        // strtok separates command line parts
        count = 0;
        char *word = strtok(line, " \t\r\n,");
        // \t\r\n checks commas and spaces
        while (word != NULL && count < 8) {
            token[count++] = word;
            word = strtok(NULL, " \t\r\n,");
        }

        if (word != NULL) {
            printf("Invalid Input.\n");
            continue;
        }
        if (count == 0) {
            continue;
        }

        /*
        If 1 token:
        list, clear, quit, "a"

        If 3 tokens:
        a + b,   a - b,   a * k,   k * a

        If 5 tokens:
        a = 1 2 3,   c = a + b,   c = a - b,   c = a * k,   c = k * a
        */


        // if single token command, check the following options
        if (count == 1) {
            if (strcmp(token[0], "quit") == 0) {
                break;
            }
            else if (strcmp(token[0], "clear") == 0) {
                clear();
                printf("Vector storage cleared.\n");
            }
            else if (strcmp(token[0], "list") == 0) {
                int found = 0;

                for (int i = 0; i < 10; i++) {
                    if (getVecAt(i, &answer)) {
                        printVec(answer);
                        found = 1;
                    }
                }
                if (!found) {
                    printf("No vectors stored.\n");
                }
            }
            else if (readStored(token[0], &answer)) {
                printVec(answer);
            }
        }

        // if 3 token command input, check the following command options
        else if (count == 3 && (strcmp(token[1], "+") == 0 ||
                 strcmp(token[1], "-") == 0 ||
                 strcmp(token[1], "*") == 0)) {
            if (checkSign(token[0], token[1], token[2], &answer)) {
                printf("ans = %.2f  %.2f  %.2f\n",
                answer.ValX, answer.ValY, answer.ValZ);
            }
        }

        // check 5 token command input options
        else if (count == 5 && strcmp(token[1], "=") == 0
                 && validName(token[0])) {
            int isCalculation = 0;

            // Check for an operator before trying to read three numbers.
            if (strcmp(token[3], "+") == 0 ||
                strcmp(token[3], "-") == 0 ||
                strcmp(token[3], "*") == 0) {
                if (!checkSign(token[2], token[3], token[4], &answer)) {
                    continue;
                }
                isCalculation = 1;
                answer.name = token[0][0];
            }
            else if (readNumber(token[2], &x) &&
                     readNumber(token[3], &y) &&
                     readNumber(token[4], &z)) {
                answer = addVect(token[0][0], x, y, z);
            }
            else {
                printf("Invalid input.\n");
                continue;
            }

            if (storeVec(answer)) {
                printVec(answer);
            }
            else {
                printf("Vector storage full. Maximum is 10.\n");

                // if storage is full tell the user and print the answer anyways
                if (isCalculation) {
                    printf("Unsaved Result: ");
                    printVec(answer);
                }
            }
        }
        else {
            printf("Invalid input.\n");
        }
    }
}


// help text with command formatting options
void help(void) {
    printf("Help command: ./vectors -h\n");
    printf("Vector names are single letters, up to 10 can be stored.\n");
    printf("Commands:\n");
    printf("  a = 1 2 3      Create or replace a vector\n");
    printf("  c = a + b      Add or subtract vectors and save the result\n");
    printf("  d = c * 2      Scalar multiplication and assignment\n");
    printf("  a + b          Calculate without saving \n");
    printf("  a - b          Subtract two vectors\n");
    printf("  a              Display one stored vector\n");
    printf("  list           Display all stored vectors\n");
    printf("  clear          Erase all stored vectors\n");
    printf("  quit           Exit the program\n");
    printf("Use spaces around =, +, -, and *.\n");
}

int main(int argc, char *argv[]) {
    if (argc == 2 && strcmp(argv[1], "-h") == 0) {
        help();
        return 0;
    }
    if (argc != 1) {
        printf("Invalid input. Use -h for help.\n");
        return 1;
    }

    interface();
    return 0;
}
