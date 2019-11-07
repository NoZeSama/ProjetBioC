#include <stdio.h>


struct sequence {
	char data;
	int count;
	struct sequence *next;
};
typedef struct sequence SEQUENCE;


SEQUENCE *reverse(SEQUENCE *S);
SEQUENCE *createSequence(FILE *f, SEQUENCE *S);
void show(SEQUENCE *S);