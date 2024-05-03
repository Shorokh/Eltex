#include <stdio.h>
#include "stringProcessing.h"

int main (){
    const int max_length=100;
    char string[max_length];
    char substring[max_length];
    get_info(string,substring,max_length);
    int string_length=0;
    int substring_length=0;
    normalize_strings_and_get_size(string,&string_length,substring,&substring_length,max_length);
    
    if_string_less_than_substring(string, string_length, substring, substring_length);
    
    int found;
    found=is_found(string, string_length, substring, substring_length);
    char *start_of_substring;
    if(found<0){
        start_of_substring=NULL;
    }
    else{
        start_of_substring=&string[found];
    }
    printf("\npointer of substring start:\n%x\n",start_of_substring);
    return 0;
}