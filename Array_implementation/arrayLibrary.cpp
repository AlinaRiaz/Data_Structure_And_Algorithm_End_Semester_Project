#include "arrayLibrary.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <limits>
using namespace std;

// ---------------- STORAGE ----------------
Student students[MAX_STUDENTS];
int student_count = 0;

Book books[MAX_BOOKS];
int book_count = 0;

// ---------------- FUNCTIONS ----------------

int find_student(int roll) {
    for (int i = 0; i < student_count; i++)
        if (students[i].roll == roll) return i;
    return -1;
}

int find_book(int isbn) {
    for (int i = 0; i < book_count; i++)
        if (books[i].isbn == isbn) return i;
    return -1;
}

void create_account() {
    if (student_count >= MAX_STUDENTS) {
        cout << "Student limit reached.\n";
        return;
    }

    int roll;
    cout << "Enter roll number: ";
    cin >> roll;

    if (find_student(roll) != -1) {
        cout << "Account already exists.\n";
        return;
    }

    students[student_count].roll = roll;
    cin.ignore(); // flush newline
    cout << "Enter student name: ";
    getline(cin, students[student_count].name);


    double deposit;
    cout << "Enter initial deposit (min $50): ";
    cin >> deposit;

    if (deposit < 50) {
        cout << "Minimum deposit is $50.\n";
        return;
    }

    students[student_count].balance = deposit - 50;
    student_count++;
}

void display(int roll) {
    int index = find_student(roll);
    if (index == -1) {
        cout << "Student not found.\n";
        return;
    }

    cout << "\nRoll: " << students[index].roll
         << "\nName: " << students[index].name
         << "\nBalance: $" << fixed << setprecision(2)
         << students[index].balance << endl;
}

void deposit_amount(int roll, double amount) {
    int index = find_student(roll);
    if (index == -1) return;

    students[index].balance += amount;
    cout << "Updated balance: $" << students[index].balance << endl;
}

void issue_item(int roll) {
    int index = find_student(roll);
    if (index == -1) return;

    cout << "\nAvailable books:\n";
    for (int i = 0; i < book_count; i++) {
        if (books[i].available) {
            cout << i + 1 << ". " << books[i].title
                 << " (" << books[i].isbn << ")\n";
        }
    }

    int choice;
    cout << "Enter book number (0 to cancel): ";
    cin >> choice;

    if (choice <= 0 || choice > book_count) return;

    if (books[choice - 1].available && students[index].balance >= 2) {
        books[choice - 1].available = false;
        students[index].balance -= 2;
        cout << "Book issued successfully.\n";
    } else {
        cout << "Issue failed.\n";
    }
}

void display_sorted() {
    for (int i = 0; i < student_count - 1; i++) {
        for (int j = i + 1; j < student_count; j++) {
            if (students[i].roll > students[j].roll) {
                swap(students[i], students[j]);
            }
        }
    }

    cout << "\nStudents List:\n";
    for (int i = 0; i < student_count; i++) {
        cout << students[i].roll << " - "
             << students[i].name << " - $"
             << students[i].balance << endl;
    }
}

void add_book() {
    if (book_count >= MAX_BOOKS) return;

    cin.ignore(); // flush newline
    cout << "Enter title: ";
    getline(cin, books[book_count].title);

    cout << "Enter author: ";
    getline(cin, books[book_count].author);

    cout << "Enter ISBN: ";
    cin >> books[book_count].isbn;

    books[book_count].available = true;
    book_count++;
}

void edit_book() {
    int isbn;
    cout << "Enter ISBN: ";
    cin >> isbn;

    int index = find_book(isbn);
    if (index == -1) return;

    cin.ignore(); // flush newline
    cout << "New title: ";
    getline(cin, books[index].title);

    cout << "New author: ";
    getline(cin, books[index].author);
}

void view_books() {
    for (int i = 0; i < book_count; i++) {
        cout << "\nTitle: " << books[i].title
             << "\nAuthor: " << books[i].author
             << "\nISBN: " << books[i].isbn
             << "\nAvailable: "
             << (books[i].available ? "Yes" : "No") << endl;
    }
}
