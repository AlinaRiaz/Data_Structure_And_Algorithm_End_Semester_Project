#ifndef ARRAY_LIBRARY_H
#define ARRAY_LIBRARY_H

#include "../Common/libraryTypes.h"

// Array storage
extern Student students[MAX_STUDENTS];
extern int student_count;

extern Book books[MAX_BOOKS];
extern int book_count;

// Array functions
int find_student(int roll);
int find_book(int isbn);

void create_account();
void display(int roll);
void deposit_amount(int roll, double amount);
void issue_item(int roll);
void display_sorted();

void add_book();
void edit_book();
void view_books();

#endif
