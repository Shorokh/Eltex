#include <stdio.h>

int main(){
    int array[10];
    int *pointer=array;
    for(int i=1;i<11;i++){
        *pointer=i;
        pointer++;
    }

    pointer=array;
    for(int i=0;i<10;i++){
        printf("%d ",*pointer);
        pointer++;
    }
    printf("\n");
}
