#include <stdio.h>


struct sequence {
	char data;
	struct sequence *next;
};
typedef struct sequence SEQUENCE;


SEQUENCE *createSequence(FILE *f);
void show(SEQUENCE *S);
void elements(SEQUENCE *S);