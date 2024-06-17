#include "../libcalc.h"
#include <stdio.h>

void menu_show(){
    printf("\nChoose action \n");
    printf("1 - Addition\n");
    printf("2 - Subtraction\n");
    printf("3 - Multiplication\n");
    printf("4 - Division\n");
    printf("5 - Quit the program\n");
}

int calculator(){
    int state, first_arg, second_arg, result;
    while (1)
    {
        menu_show();
        scanf("%d",&state);
        switch (state)
        {
        case 1:
            printf("Print first summand:");
            scanf("%d",&first_arg);
            printf("Print second summand:");
            scanf("%d",&second_arg);
            result=add(first_arg,second_arg);
            printf("Result: %d\n", result);
            break;
        case 2:
            printf("Print minuend:");
            scanf("%d",&first_arg);
            printf("Print subtrahend:");
            scanf("%d",&second_arg);
            result=sub(first_arg,second_arg);
            printf("Result: %d\n", result);
            break;
        case 3:
            printf("Print first multiplier:");
            scanf("%d",&first_arg);
            printf("Print second multiplier:");
            scanf("%d",&second_arg);
            result=mul(first_arg,second_arg);
            printf("Result: %d\n", result);
            break;
        case 4:
            printf("Print dividend:");
            scanf("%d",&first_arg);
            printf("Print divisor:");
            scanf("%d",&second_arg);
            result=div(first_arg,second_arg);
            printf("Result: %d\n", result);
            break;
        case 5:
            return 0;
            break;
        default:
            printf("Comand must be positive intrger between 1 and 5\n");
            break;
        }
    }
}