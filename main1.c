#include <stdio.h>
#include <stdlib.h>
#include "distance.h"


int main() {
	char *filename1 = getFilename(); 
	SEQUENCE S1 = readFile(filename1);
    char *filename2 = getFilename(); 
	SEQUENCE S2 = readFile(filename2);
    show(S1);
    show(S2);
    DISTANCE D1 = hammingDistance(S1, S2);
    DISTANCE D2 = levenshteinDistance(S1, S2);
    DISTANCE D3 = levenshteinDistance(S2, S1);
    printf("Distance d'édition (Hamming) = %.1f\n", D1.dist);
    printf("Distance d'édition (Levenshtein) = %.1f\n", D2.dist);
    printf("Distance d'édition (Levenshtein) = %.1f\n", D3.dist);
    freeSequence(&S1);
    freeSequence(&S2);
    free(filename1);
    free(filename2);
	return 0;
}