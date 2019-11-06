#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sequence.h"


SEQUENCE *createSequence(FILE *f) {
    char buffer[64];
    fgets(buffer, sizeof(buffer), f);
    SEQUENCE *S, *head, *current = NULL;
    for(int i = 0; buffer[i] != '\0'; i++) {
        S = malloc(sizeof(SEQUENCE));
        S->data = buffer[i];  
        if(current)
            current->next = S;
        else
            head = S;
        current = S;
    }
    return head;
}

void show(SEQUENCE *S) {
 	if(S) {
 		printf("%c ", S->data);
 		show(S->next);
 	} else
 		printf("\n");
}

void elements(SEQUENCE *S) {
 	int n = 0;
 	while(S) {
 		n++;
        S = S->next;
 	}
 	printf("There is %d nucleotides in the sequence\n", n);
}