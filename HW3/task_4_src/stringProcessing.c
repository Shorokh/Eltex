#include "stringProcessing.h"
#include <stdio.h>

void get_info(char *string, char *substring, const int max_length){
    printf("Enter the string in which to search for the substring:\n");
    fgets(string, max_length, stdin);
    printf("Enter the substring:\n");
    fgets(substring, max_length, stdin);
    printf("\n");
}

void normalize_strings_and_get_size(char *string, int *string_length, char *substring, int *substring_length, const int max_length){
    for (int i = 0; i < max_length; i++){
        if (string[i] == '\n'){
            string[i] = '\0';
            break;
        }
        *string_length += 1;
    }
    for (int i = 0; i < max_length; i++){
        if (substring[i] == '\n'){
            substring[i] = '\0';
            break;
        }
        *substring_length += 1;
    }
    print(string, *string_length);
    print(substring, *substring_length);
}

void if_string_less_than_substring(char *string, int string_length, char *substring, int substring_length){
    if (substring_length > string_length){
        printf("Length of string is less then substring\n");
        printf("Swap strings\n");
        char tmp;
        for (int i = 0; i < string_length; i++){
            tmp = string[i];
            string[i] = substring[i];
            substring[i] = tmp;
        }
        for (int i = string_length; i < substring_length; i++){
            string[i] = substring[i];
            substring[i] = '\0';
        }
        tmp = string_length;
        string_length = substring_length;
        substring_length = (int)tmp;
    }
}

void print(char *string, int string_lenght){
    for (int i = 0; i < string_lenght; i++){
        printf("%c<-%x ", string[i], &string[i]);
    }
    printf("\n");
}

int is_found(char *string, int string_length, char *substring, int substring_length){
    int found = 0;
    for(int i=0;i<(string_length-substring_length);i++){
        if(string[i]!=substring[0]){
            continue;
        }
        else{
            found=1;
            for(int j=1;j<substring_length;j++){
                if(string[i+j]!=substring[j]){
                    break;
                }
                found++;
            }
            if(found==substring_length){
                return i;
            }
            
        }
    }
    return -1;
}