#include "../hdr/subscriber.h"

void string_trim(char* string, int string_size){
    for(int i=0;i<string_size;i++){
        if(string[i]=='\n'){
            string[i]='\0';
            break;
        }
    }
}

void fillEmpty(struct subscriber** subscriber_book,int currentBookSize){
    for(int i=0;i<max_length;i++){
        (*subscriber_book)[currentBookSize].name[i]='\0';
        (*subscriber_book)[currentBookSize].second_name[i]='\0';
    }
    for(int i=0;i<phone_length;i++){
        (*subscriber_book)[currentBookSize].phone_number[i]='\0';
    }
}

void add_subscriber(struct subscriber** subscriber_book, int *currentBookSize){
    fflush(stdin);
    struct subscriber* tmp =(struct subscriber*)realloc(*subscriber_book,(*currentBookSize+1)*sizeof(struct subscriber));
    if(tmp==NULL){
        printf("Impossible to allocate memory\n");
        exit(1);
    }
    *subscriber_book = tmp;
    fillEmpty(subscriber_book,*currentBookSize);
    getchar();
    printf("Input name: ");
    string_trim((*subscriber_book)[*currentBookSize].name,max_length);
    fgets((*subscriber_book)[*currentBookSize].name,max_length,stdin);
    if((*subscriber_book)[*currentBookSize].name[max_length-2]!='\0'){
        while(getchar()!='\n');
    }
    string_trim((*subscriber_book)[*currentBookSize].name,max_length);
    
    printf("Input second name: ");
    fgets((*subscriber_book)[*currentBookSize].second_name,max_length,stdin);
    if((*subscriber_book)[*currentBookSize].second_name[max_length-2]!='\0'){
        while(getchar()!='\n');
    }
    string_trim((*subscriber_book)[*currentBookSize].second_name,max_length);

    printf("Input phone number: ");
    fgets((*subscriber_book)[*currentBookSize].phone_number,phone_length,stdin);
    if((*subscriber_book)[*currentBookSize].phone_number[phone_length-2]!='\0'){
        while(getchar()!='\n');
    }
    string_trim((*subscriber_book)[*currentBookSize].phone_number,phone_length);

    print_subscriber(subscriber_book,*currentBookSize);
    *currentBookSize+=1;
    //print_all_subscribers(subscriber_book,*currentBookSize);  
}

void print_subscriber(struct subscriber** subscriber_book, int current_pos){
    //printf("%s %s %s\n",*subscriber_book[current_pos].name,*subscriber_book[current_pos].second_name,*subscriber_book[current_pos].phone_number);
    for(int j=0;j<max_length;j++){
        printf("%c",(*subscriber_book)[current_pos].name[j]);
    }
    printf(" ");
    for(int j=0;j<max_length;j++){
        printf("%c",(*subscriber_book)[current_pos].second_name[j]);
    }
    printf(" ");
    for(int j=0;j<phone_length;j++){
        printf("%c",(*subscriber_book)[current_pos].phone_number[j]);
    }
    printf(" \n");
}

void print_all_subscribers(struct subscriber** subscriber_book, int currentBookSize){
    for(int i=0;i< currentBookSize;i++){
        printf("%d) ",(i+1));
        print_subscriber(subscriber_book,i);
    }
}

void find_by_name(struct subscriber** subscriber_book, int currentBookSize){
    char name_to_find[max_length];
    for(int i=0;i<max_length;i++){
        name_to_find[i]='\0';
    }
    getchar();
    printf("Input name: ");
    fgets(name_to_find,max_length,stdin);
    if(name_to_find[max_length-1]!='\0'){
        while(getchar()!='\n'){}
    }
    string_trim(name_to_find,max_length);
    int flag_found=0;
    int found_count=0;
    for(int i=0;i<currentBookSize;i++){
        flag_found=1;
        for(int j=0;j<max_length;j++){
            if((*subscriber_book)[i].name[j]!=name_to_find[j]){
                flag_found=0;
                break;
            }
        }
        if(flag_found==1){
            if(found_count==0){
                printf("Found subscribers:\n");
                found_count++;
            }
            print_subscriber(subscriber_book,i);
        }
    }
}

void delete_by_number(struct subscriber** subscriber_book,int *currentBookSize){
    int number_to_delete=-1;
    print_all_subscribers(subscriber_book,*currentBookSize);
    getchar();
    printf("Which subscriber to delete, input number:");
    scanf("%d",&number_to_delete);
    
    if(number_to_delete<=*currentBookSize&&number_to_delete>0){
        for(int j=0;j<max_length;j++){
            (*subscriber_book)[number_to_delete-1].name[j]=(*subscriber_book)[*currentBookSize-1].name[j];
        }
        for(int j=0;j<max_length;j++){
            (*subscriber_book)[number_to_delete-1].second_name[j]=(*subscriber_book)[*currentBookSize-1].second_name[j];
        }
        for(int j=0;j<phone_length;j++){
            (*subscriber_book)[number_to_delete-1].phone_number[j]=(*subscriber_book)[*currentBookSize-1].phone_number[j];
        }
        //*currentBookSize-=1;
        struct subscriber* tmp =(struct subscriber*)realloc(*subscriber_book,(*currentBookSize)*sizeof(struct subscriber));
        if(tmp==NULL){
            printf("Impossible to allocate memory\n");
            exit(1);
        }
        *subscriber_book = tmp;
        *currentBookSize-=1;
        print_all_subscribers(subscriber_book, *currentBookSize);
        
    }else{
        printf("Wrong input\n");
    }
}