#ifndef LIBRARY_TYPES_H
#define LIBRARY_TYPES_H

#include <string>
using namespace std;

#define TABLE_SIZE 10   // SINGLE SOURCE OF TRUTH

struct Student {
    int roll;
    string name;
    double balance;
    Student* next;
};

struct Book {
    int isbn;
    string title;
    string author;
    bool available;
    int issuedTo;
    Book* next;
};

#endif
