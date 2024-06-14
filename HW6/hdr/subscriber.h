#pragma once
#include <stdio.h>
#include <stdlib.h>

#define max_length 21
#define phone_length 12

struct subscriber{
    char name[max_length];
    char second_name[max_length];
    char phone_number[phone_length];
};

void add_subscriber(struct subscriber** subscriber_book, int *currentBookSize);
void print_subscriber(struct subscriber** subscriber_book, int current_pos);
void print_all_subscribers(struct subscriber** subscriber_book,int currentBookSize);
void find_by_name(struct subscriber** subscriber_book, int currentBookSize);
void delete_by_number(struct subscriber** subscriber_book, int *currentBookSize);
void fillEmpty(struct subscriber** subscriber_book,int currentBookSize);

void string_trim(char* string, int string_size);