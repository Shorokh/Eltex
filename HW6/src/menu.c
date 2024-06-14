#include "../hdr/menu.h"

int menu_show(struct subscriber** subscriber_book, int* currentBookSize){
    int action;
    printf("\nChoose action:\n");
    printf("1 - Add new subscriber\n");
    printf("2 - Delete specific subscriber\n");
    printf("3 - Find subscribers by name\n");
    printf("4 - Show all subscribers\n");
    printf("5 - Quit\n");
    scanf("%d",&action);
    switch (action){
    case 1:
        add_subscriber(subscriber_book, currentBookSize);    
        menu_show(subscriber_book, currentBookSize);
        return 0;
        break;
    case 2:
        delete_by_number(subscriber_book, currentBookSize);
        menu_show(subscriber_book, currentBookSize);
        return 0;
        break;
    case 3:
        find_by_name(subscriber_book, *currentBookSize);
        menu_show(subscriber_book, currentBookSize);
        return 0;
        break;
    case 4:
        print_all_subscribers(subscriber_book, *currentBookSize);
        menu_show(subscriber_book, currentBookSize);
        return 0;
        break;
    case 5:
        return 1;
        break;
    default:
        getchar();
        printf("The input is incorrect, try again.\n");
        menu_show(subscriber_book,currentBookSize);
        return 0;
        break;
    }
    return 0;
}