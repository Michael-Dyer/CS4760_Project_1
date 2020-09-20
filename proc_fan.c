#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>

//self note: get proc fan to fork only one thing
int main (int argc, char* argv[]){
	int pr_limit; //max children proccesse
	int pr_count = 0; //current children
	int opt;

	pid_t childpid = 0;




	while((opt = getopt(argc, argv, "n:h")) != -1)
	switch (opt) {
		case 'n':
			//changes number allowed
			//
			break;
		case 'h':
			//print help
	}//self note: make default number for n if n isn't specified
	//show number in help msg	

return 0;
}
