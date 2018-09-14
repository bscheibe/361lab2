#include "mycopy.h"
extern int errno;
#define BUFFERSIZE 4096

int main(int argc, char *argv[]) {
	char ovrchk[8];
	char buffer[BUFFERSIZE];
	int i;

	if (argc != 3) {
		printf("ERROR: Need exactly two arguments.");
		return -1;
	}// Not enough arguments to continue properly.
	if (access(argv[1],R_OK) < 0) {
		printf("ERROR: cannot access input file.");
		return -1;
	}// Read error.
	if (access(argv[2],X_OK) == 0) {
		printf("Output file exists. Overwrite? (y/n):");
		scanf("%s",ovrchk);
		if (strcmp(ovrchk, "y") != 0){
			printf("%s",ovrchk);
			return 0;
		}// User does not wish to proceed with overwrite.
	}// Check if file exists.

	int source = open(argv[1], O_RDONLY);
	if (source < 0) {
		printf("ERROR: bad input filename.");
		return -1;
	}// Bad input.

	int destination = open(argv[2], O_WRONLY | O_CREAT);

	while ((i = read(source, buffer, BUFFERSIZE)) > 0) {
		if (write(destination, buffer, i) != i)
			printf("Write error.");
		if (i < 0)
			printf("Read error.");
	}

	close(source);
	close(destination);

	return 0;
}
