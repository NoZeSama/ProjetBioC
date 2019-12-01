#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sequence.h"


char *getFilename() {
    char *filename;
    printf("What file do you want to open?\n");
    scanf("%ms", &filename);
    return filename;
}


SEQUENCE readFile(char *filename) {
    FILE *f;
    char *tmp;
    SEQUENCE S;
    if(!(f = fopen(filename, "r"))) {
        printf("Cannot open file");
        exit(1);         
    }
    fscanf(f, "%m[^\n]", &tmp);
    fclose(f);
    S.len = strlen(tmp);
    S.data = tmp;
    return S;
} 


void show(SEQUENCE S) {
    printf("Sequence is: \n%s\n", S.data);
}


void freeSequence(SEQUENCE *S) {
    free(S->data);
    S->data = NULL;
}