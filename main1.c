#include <stdio.h>
#include <stdlib.h>
#include "sequence.h"
#include "distance.h"


int main(int argc, char *argv[]) {
	SEQUENCE *S1 = NULL;
	FILE *f1 = NULL;
	f1 = fopen(argv[1], "r");
	S1 = createSequence(f1, S1);
	S1 = reverse(S1);
	show(S1);
	fclose(f1);

	SEQUENCE *S2 = NULL;
	FILE *f2 = NULL;
	f2 = fopen(argv[2], "r");
	S2 = createSequence(f2, S2);
	S2 = reverse(S2);
	show(S2);
	fclose(f2);

	SEQUENCE *S3 = NULL;
	FILE *f3 = NULL;
	f3 = fopen(argv[3], "r");
	S3 = createSequence(f3, S3);
	S3 = reverse(S3);
	show(S3);
	fclose(f3);

	SEQUENCE *S4 = NULL;
	FILE *f4 = NULL;
	f4 = fopen(argv[4], "r");
	S4 = createSequence(f4, S4);
	S4 = reverse(S4);
	show(S4);
	fclose(f4);

	SEQUENCE *S5 = NULL;
	FILE *f5 = NULL;
	f5 = fopen(argv[5], "r");
	S5 = createSequence(f5, S5);
	S5 = reverse(S5);
	show(S5);
	fclose(f5);
	
	return 0;
}