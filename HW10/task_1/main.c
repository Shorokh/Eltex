#include <stdio.h> 
#include <sys/types.h> 
#include <sys/wait.h>
#include <unistd.h> 
#include <stdlib.h>

int main() 
{ 
	pid_t p = fork();                               //create process
	if(p<0){                                        //if process not created, something went wrong
	    perror("fork fail"); 
	    exit(1); 
	} 
    else if(p==0){                                  //there is child
        printf("Child PID = %d \n",getpid());
        printf("Child PPID = %d \n",getppid());
        exit(0);
    }
    else{                                           //there is parent
        printf("Parent PID = %d \n",getpid());
        printf("Parent PPID = %d \n",getppid());
        wait(NULL);
    }
	return 0; 
} 
