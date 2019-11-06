#include <stdio.h>
#include <stdlib.h>
#include "sequence.h"
#include "distance.h"


int main(int argc, char *argv[]) {
	SEQUENCE *S1 = NULL;
	FILE *f1 = NULL;
	f1 = fopen(argv[1], "r");
	S1 = createSequence(f1);
	fclose(f1);
	show(S1);
	elements(S1);

	SEQUENCE *S2 = NULL;
	FILE *f2 = NULL;
	f2 = fopen(argv[2], "r");
	S2 = createSequence(f2);
	fclose(f2);
	show(S2);
	elements(S2);
	
	return 0;
}