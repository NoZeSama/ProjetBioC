typedef struct {
	int len;
	char *data;
} SEQUENCE;


//Function that returns a char* holding the file name
char *getFilename();

//Function that opens the given file name and returns a SEQUENCE holding the data's file
SEQUENCE readFile(char* filename);

//Utility function that prints the given SEQUENCE
void show(SEQUENCE S);

//Function that frees the memory for the given SEQUENCE
void freeSequence(SEQUENCE *S);