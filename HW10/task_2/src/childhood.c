#include "../hdr/childhood.h"

void generateAllChild(){
    printHeader();
    printf("Parent\t\t%d\t\t%d\n",getpid(),getppid());
    int childStatus1, childStatus2, childStatus3, childStatus4, childStatus5;
    pid_t pidChild1=fork();
    if(pidChild1<0){
        printf("Error on fork child 1\n");
        exit(-1);
    }
    else if(pidChild1==0){
        printf("Child 1\t\t%d\t\t%d\n",getpid(),getppid());
        genChild3(&childStatus3);
        genChild4(&childStatus4);
        exit(1);        
    }else{
        pid_t pidChild2=fork();
        if(pidChild2<0){
            printf("Error on fork child 2\n");
            exit(-1);
        }
        else if(pidChild2==0){
            printf("Child 2\t\t%d\t\t%d\n",getpid(),getppid());
            genChild5(&childStatus5);
            exit(2);
        }
        else{
            wait(&childStatus1);
            wait(&childStatus2);
        }
    }
}

void genChild3(int *childStatus3){
    pid_t pidChild3=fork();
    if(pidChild3<0){
        printf("Error on fork child 3\n");
        exit(-1);
    }
    else if(pidChild3==0){
        printf("Child 3\t\t%d\t\t%d\n",getpid(),getppid());
        exit(3);
    }
    else{
        wait(childStatus3);
    }
}

void genChild4(int *childStatus4){
    pid_t pidChild4=fork();
    if(pidChild4<0){
        printf("Error on fork child 4\n");
        exit(-1);
    }
    else if(pidChild4==0){
        printf("Child 4\t\t%d\t\t%d\n",getpid(),getppid());
        exit(4);
    }
    else{
        wait(childStatus4);
    }
}

void genChild5(int *childStatus5){
    pid_t pidChild5=fork();
    if(pidChild5<0){
        printf("Error on fork child 5\n");
        exit(-1);
    }
    else if(pidChild5==0){
        printf("Child 5\t\t%d\t\t%d\n",getpid(),getppid());
        exit(5);
    }
    else{
        wait(childStatus5);
    }  
}