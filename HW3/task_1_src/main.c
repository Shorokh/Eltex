#include <stdio.h>

int main(){
    int number=0;
    printf("Please, type positive integer number in which to change 3rd byte: ");
    scanf("%d",&number);
    while(number<0){
        printf("Number must be positive integer! Please, input correct number");
        scanf("%d",&number);
    }
    printf("Please, type positive integer number, ranging from 0 to 255: ");
    int switcher=0;
    scanf("%d",&switcher);
    while(switcher<0||switcher>255){
        if(switcher<0){
            printf("Number must be positive! Please, input correct number:");
        }
        if(switcher>255){
            printf("Number must less than 256! Please, input correct number:");           
        }
        scanf("%d",&switcher);
    }
    
    unsigned char *pointer=&number;
    unsigned char buffer[4];
    for(int i=0;i<4;i++){
        buffer[i]=*pointer;
        pointer++;
    }
    
    pointer=&number;
    pointer+=2;
    printf("Number by the bytes:\n");
    for(int i=0;i<4;i++){
        printf("%d",buffer[3-i]);
        if(i==1){
            printf("->%d",switcher);
        }
        printf("\t");
    }
    printf("\n");

    *pointer=switcher;
    printf("%d",number);
    printf("\n");
    return 0;
}