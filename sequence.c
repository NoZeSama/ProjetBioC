#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sequence.h"


SEQUENCE *reverse(SEQUENCE *S) {
    if(!S || !S->next)
        return S;
    SEQUENCE *tmp = S->next;
    SEQUENCE *res = reverse(S->next);
    tmp->next = S;
    S->next = NULL;
    return res;
}

SEQUENCE *createSequence(FILE *f, SEQUENCE *S) {
    char buffer[20];
    fgets(buffer, sizeof(buffer), f);
    SEQUENCE *new;
    new = NULL;
    for(int i = 0 ; buffer[i] != '\0'; i++) {
        new = malloc(sizeof(SEQUENCE));
        new->data = buffer[i];
        new->count = i;
        new->next = S;
        S = new;
    }
    return S;
}

void show(SEQUENCE *S) {
 	if(S) {
 		printf("%c", S->data);
        printf("%d ", S->count);
 		show(S->next);
 	} else
 		printf("\n");
}