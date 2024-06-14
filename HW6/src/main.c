#include <stdio.h>
#include <stdlib.h>
#include "../hdr/menu.h"
#include "../hdr/subscriber.h"

int main(){
    //int action=menu_show();
    int currentBookSize=0; 
    struct subscriber *subscriber_book=(struct subscriber*)calloc(1,sizeof(struct subscriber));
    menu_show(&subscriber_book,&currentBookSize);
    free(subscriber_book);
    subscriber_book=NULL;
    return 0;
}