#include "../hdr/executor.h"


int commandInterpreter(){
    char line[MAX_LINE_LENGTH];
    char* args[MAX_ARGS];
    int status;

    while (1) {
        printf("not bash> ");
        fgets(line, MAX_LINE_LENGTH, stdin);

        // tokenize the input
        int i = 0;
        args[i] = strtok(line, " \n");
        while (args[i] != NULL) {
            i++;
            args[i] = strtok(NULL, " \n");
        }
        args[i] = NULL;
        if (strcmp(args[0], "cd") == 0) {
            chdir(args[1]);
            continue;
        }
        if (strcmp(args[0], "exit") == 0) {
            return 0;
        }

        // create a child process and execute the command
        pid_t pid = fork();
        if (pid < 0) {
            perror("fork failed");
            exit(0);
        }
        else if (pid == 0) {
            // child process
            execvp(args[0], args);
            perror("execvp failed");
            exit(1);
        }
        else {
            // parent process
            waitpid(pid, &status, 0);
        }
    }
}