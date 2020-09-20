#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>


int main (int argc, char* argv[]){

	if (argc != 3) {
		perror("Error: testsim needs 2 args from cl");
		return 0;
	}

	printf(argv[1]);
	printf("\n");
	printf(argv[2]);





return 0;
}
