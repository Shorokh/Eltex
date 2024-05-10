#pragma once
#include <stdio.h>

#define max_length 21
#define phone_length 12
#define book_size 10

struct subscriber{
    char name[max_length];
    char second_name[max_length];
    char phone_number[phone_length];
};

void clear_book(struct subscriber* subscriber_book);
void add_subscriber(struct subscriber* subscriber_book, int *end_of_book);
void print_subscriber(struct subscriber* subscriber_book, int current_pos);
void print_all_subscribers(struct subscriber* subscriber_book);
void find_by_name(struct subscriber* subscriber_book);
void delete_by_number(struct subscriber* subscriber_book);


void string_trim(char* string, int string_size);