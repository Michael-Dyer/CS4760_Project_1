#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>
#include <sys/types.h>
#include <sys/wait.h>

#ifndef MAX_CANON
#define MAX_CANON 8192
#endif


char** make_execv_arr(char* str);

int main (int argc, char* argv[]){
	int pr_limit = 4; //max children proc allowed at once
	int pr_count = 0; //current children
	int opt;
	char cmd[MAX_CANON];//cmd for fgets
	
	pid_t childpid = 0;
	int status;

	char* execv_arr; //array arg passed to execv to run process

	while((opt = getopt(argc, argv, "n:h")) != -1)
	switch (opt) {
		case 'n':
			//changes number allowed
			pr_limit = atoi(optarg);	
			break;
		case 'h':
			printf("To run program, execute; proc_fan [-n n] process\n");
			printf("n here is max number of processes running at once\n");
			printf("n default will be 4\n");
			return 0;//exit if help is used
		}

	//this code will fork ls from program
	/*
    char *args[2];

    args[0] = "/bin/ls";        // first arg is the full path to the executable
    args[1] = NULL;             // list of args must be NULL terminated

    if ( fork() == 0 )
        execv( args[0], args ); // child: call execv with the path and the args
    else
        wait( &status );    	
	*/ 			
	
	//reads std in (from book)
	
	while(fgets(cmd, MAX_CANON, stdin) != NULL){
		printf(cmd)	;
	}
	

return 0;
}
