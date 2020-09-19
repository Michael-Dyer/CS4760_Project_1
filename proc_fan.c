#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>


int main (int argc, char* argv[]){
	int pr_limit; //max children proccesse
	int pr_count = 0; //current children
	int opt;

	pid_t childpid = 0;

	while((opt = getopt(argc, argv, "n:h")) != -1)
	switch (opt) {
		case 'n':
			//
			//
			break;
		case 'h':
			printf("help blah blah");
			break;		

	}	

return 0;
}
