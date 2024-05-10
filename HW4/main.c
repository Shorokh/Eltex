#include <stdio.h>
#include "menu.h"
#include "subscriber.h"

int main(){
    //int action=menu_show();
    int end_of_book=0; 
    struct subscriber subscriber_book[book_size];
    clear_book(subscriber_book);
    menu_show(subscriber_book,&end_of_book);
    
    return 0;
}