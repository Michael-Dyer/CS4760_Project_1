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


char** make_execv_arr(char *line);

int main (int argc, char* argv[]){
	int pr_limit = 4; //max children proc allowed at once
	int pr_count = 0; //current children
	int opt;
	char cmd[MAX_CANON];//cmd for fgets
	
	pid_t childpid = 0;
	int status;
	

	char** execv_arr; //array arg passed to execv to run process

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


	if (pr_limit < 1){
		perror("Error: pr_limit (set with -n flag) must be larger than 0"); 
		return -1;
	}
	
	//reads std in line by line(from book)
	while(fgets(cmd, MAX_CANON, stdin) != NULL){
			
		//this function converts lines into array of words
		//for execv to call	
		execv_arr = make_execv_arr(cmd);

		//wait untill pr_limit isn't filled and decrement	
		if (pr_count == pr_limit) {
			printf("waiting until pr_count != pr_limit\n");
			wait(NULL);
			pr_count--;
		}
	
		//fork off
    	if ((childpid = fork()) == 0 ){
			printf ( "pr_count is %d \n", pr_count);
        	if (execv( execv_arr[0], execv_arr ) == -1){
				perror("Error: failed to execute command"); //make sure execv works
			}
		}
    	else
        	wait( &status );    	

		
	if (childpid < 0) {
		perror("Error: fork() failed");
		return -1;
	}	
	
	pr_count++;

	if (waitpid(-1, NULL, WNOHANG) > 0) {
		pr_count--;
	}	

	
	}//end of while loop

return 0;
}



//takes line from cmd and returns an array for execv
char** make_execv_arr(char *line){
	char *token;

	char** exe_arr = malloc(MAX_CANON * sizeof(char *));
	
	token = strtok(line, " ");//splits into tokens

	int arr_pos = 0;
	while (token != NULL) {
		//printf(" %s\n", token);
		exe_arr[arr_pos] = malloc(30);//longest string allowed	
		exe_arr[arr_pos] = token;
		
		arr_pos++;	
		token = strtok(NULL, " ");//shifts to next token
	}
	
	exe_arr[arr_pos] = NULL; //make last char NULL to work with execv
	return exe_arr;

}
