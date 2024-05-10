#include "menu.h"

int menu_show(struct subscriber* subscriber_book, int* end_of_book){
    int action;
    printf("\nChoose action:\n");
    if(*end_of_book<book_size)
        printf("1 - Add new subscriber\n");
    else
        printf("Addition of new subscribers is impossible - the book is fool\n");
    printf("2 - Delete specific subscriber\n");
    printf("3 - Find subscribers by name\n");
    printf("4 - Show all subscribers\n");
    printf("5 - Quit\n");
    
    scanf("%d",&action);
    switch (action){
    case 1:
        if(*end_of_book<book_size)
            add_subscriber(subscriber_book, end_of_book);    
        menu_show(subscriber_book, end_of_book);
        return 0;
        break;
    case 2:
        delete_by_number(subscriber_book);
        menu_show(subscriber_book, end_of_book);
        return 0;
        break;
    case 3:
        find_by_name(subscriber_book);
        menu_show(subscriber_book, end_of_book);
        return 0;
        break;
    case 4:
        print_all_subscribers(subscriber_book);
        menu_show(subscriber_book, end_of_book);
        return 0;
        break;
    case 5:
        return 1;
        break;
    default:
        getchar();
        printf("The input is incorrect, try again.");
        menu_show(subscriber_book,end_of_book);
        return 0;
        break;
    }
    return 0;
}