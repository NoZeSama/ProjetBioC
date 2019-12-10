#include <stdio.h>
#include <stdlib.h>
#include "distance.h"

int max(SEQUENCE S1, SEQUENCE S2) {
	if(S1.len >= S2.len)
		return S1.len;
	else
		return S2.len;
}

float min(float del, float ins, float sub) {
	if(del <= ins && del <= sub)
		return del;
	if(ins <= del && ins <= sub)
		return ins;
	else
		return sub;
}


float charDistance(char C1, char C2) {
	switch(C1) {	
		case 'A':
			switch(C2) {			
				case 'A': return 0.0;
				case 'C': return 2.0;
				case 'G': return 1.0;
				case 'T': return 2.0;
				default : return 1.5;
			}
		case 'C':
			switch(C2) {			
				case 'A': return 2.0;
				case 'C': return 0.0;
				case 'G': return 2.0;
				case 'T': return 1.0;
				default : return 1.5;
			}
		case 'G':
			switch(C2) {			
				case 'A': return 1.0;
				case 'C': return 2.0;
				case 'G': return 0.0;
				case 'T': return 2.0;
				default : return 1.5;
			}
		case 'T':
			switch(C2) {			
				case 'A': return 2.0;
				case 'C': return 1.0;
				case 'G': return 2.0;
				case 'T': return 0.0;
				default : return 1.5;
			}
		default: return 1.5;
	}
}


DISTANCE hammingDistance(SEQUENCE S1, SEQUENCE S2) {
	char C1, C2;
	DISTANCE D;
	D.dist = 0.0;
	for(int i = 0; i < max(S1, S2); i++) {
		C1 = S1.data[i];
		C2 = S2.data[i];
		D.dist += charDistance(C1,C2);
	}
	return D;
}


DISTANCE levenshteinDistance(SEQUENCE S1, SEQUENCE S2) {
	DISTANCE D;
	D.dist = 0.0;
	float arrayD[S1.len + 1][S2.len + 1];
	for(int i = 0; i < S1.len; i++)
		arrayD[i][0] = i;
	for(int j = 0; j < S2.len; j++)
		arrayD[0][j] = j;
	for(int m = 1; m < S1.len; m++) {
		for(int n = 1; n < S2.len; n++) {
			if(S1.data[m - 1] != S2.data[n - 1])
				D.dist += charDistance(S1.data[m], S2.data[n]);
			arrayD[m][n] = min(arrayD[m - 1][n] + 1,
							   arrayD[m][n - 1] + 1,
							   arrayD[m - 1][n - 1] + charDistance(S1.data[m], S2.data[n]));		}
	}
	D.dist = arrayD[S1.len - 1][S2.len - 1];
	return D;
}