#include "sequence.h"

typedef struct {
	float dist;
} DISTANCE;

//Function that returns the distance between two given sequences without optimization
DISTANCE hammingDistance(SEQUENCE S1, SEQUENCE S2);

//Function that returns the distance between two given sequences with recursive optimization
DISTANCE levenshteinDistance(SEQUENCE S1, SEQUENCE S2);