#ifndef HASH_LIBRARY_H
#define HASH_LIBRARY_H

#include "../Common/libraryTypes.h"

#ifdef _WIN32
#define EXPORT __declspec(dllexport)
#else
#define EXPORT
#endif

// Hash tables
extern Student* studentTable[TABLE_SIZE];
extern Book* bookTable[TABLE_SIZE];

// Function declarations
EXPORT void initLibrary();

// Student functions
EXPORT void createStudent(int roll, const char* name, double balance);
EXPORT void viewStudent(int roll, char* buffer, int bufSize);
EXPORT void depositAmount(int roll, double amount);

// Book functions
EXPORT void addBook(int isbn, const char* title, const char* author);
EXPORT void viewBooks(char* buffer, int bufSize);
EXPORT void issueBook(int roll, int isbn);
EXPORT void returnBook(int roll, int isbn);

#endif
