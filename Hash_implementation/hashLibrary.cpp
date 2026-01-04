#include "hashLibrary.h"
#include <fstream>
#include <sstream>
#include <iomanip>

Student* studentTable[TABLE_SIZE] = { nullptr };
Book* bookTable[TABLE_SIZE] = { nullptr };

int hashStudent(int roll) { return roll % TABLE_SIZE; }
int hashBook(int isbn) { return isbn % TABLE_SIZE; }

// ===== FILE HANDLING =====
void saveStudents() {
    std::ofstream f("data/students.txt");
    for (int i=0;i<TABLE_SIZE;i++)
        for (Student* s=studentTable[i]; s; s=s->next)
            f << s->roll << "|" << s->name << "|" << s->balance << "\n";
}

void saveBooks() {
    std::ofstream f("data/books.txt");
    for (int i=0;i<TABLE_SIZE;i++)
        for (Book* b=bookTable[i]; b; b=b->next)
            f << b->isbn << "|" << b->title << "|" << b->author
              << "|" << b->available << "|" << b->issuedTo << "\n";
}

void loadStudents() {
    std::ifstream f("data/students.txt");
    std::string line;
    while (getline(f,line)) {
        std::stringstream ss(line);
        std::string roll_s,name_s,balance_s;
        getline(ss,roll_s,'|'); getline(ss,name_s,'|'); getline(ss,balance_s,'|');
        int roll = stoi(roll_s);
        double balance = stod(balance_s);
        Student* s = new Student{roll,name_s,balance,studentTable[hashStudent(roll)]};
        studentTable[hashStudent(roll)] = s;
    }
}

void loadBooks() {
    std::ifstream f("data/books.txt");
    std::string line;
    while (getline(f,line)) {
        std::stringstream ss(line);
        std::string isbn_s,title_s,author_s,avail_s,issued_s;
        getline(ss,isbn_s,'|'); getline(ss,title_s,'|'); getline(ss,author_s,'|');
        getline(ss,avail_s,'|'); getline(ss,issued_s,'|');
        int isbn = stoi(isbn_s);
        bool available = stoi(avail_s);
        int issuedTo = stoi(issued_s);
        Book* bk = new Book{isbn,title_s,author_s,available,issuedTo,bookTable[hashBook(isbn)]};
        bookTable[hashBook(isbn)] = bk;
    }
}

// ===== INIT =====
EXPORT void initLibrary() {
    loadStudents();
    loadBooks();
}

// ===== STUDENT OPS =====
Student* findStudent(int roll) {
    for (Student* s=studentTable[hashStudent(roll)]; s; s=s->next)
        if (s->roll==roll) return s;
    return nullptr;
}

EXPORT void createStudent(int roll, const char* name, double balance) {
    if (findStudent(roll)) return;
    Student* s = new Student{roll,name,balance-20,studentTable[hashStudent(roll)]};
    studentTable[hashStudent(roll)] = s;
    saveStudents();
}

EXPORT void viewStudent(int roll, char* buffer, int bufSize) {
    Student* s = findStudent(roll);
    if (!s) {
        snprintf(buffer,bufSize,"Student not found");
        return;
    }
    snprintf(buffer,bufSize,"Roll: %d\nName: %s\nBalance: %.2f", s->roll, s->name.c_str(), s->balance);
}

EXPORT void depositAmount(int roll, double amount) {
    Student* s = findStudent(roll);
    if (!s) return;
    s->balance += amount;
    saveStudents();
}

// ===== BOOK OPS =====
Book* findBook(int isbn) {
    for (Book* b=bookTable[hashBook(isbn)]; b; b=b->next)
        if (b->isbn==isbn) return b;
    return nullptr;
}

EXPORT void addBook(int isbn, const char* title, const char* author) {
    if (findBook(isbn)) return;
    Book* b = new Book{isbn,title,author,true,-1,bookTable[hashBook(isbn)]};
    bookTable[hashBook(isbn)] = b;
    saveBooks();
}

EXPORT void viewBooks(char* buffer, int bufSize) {
    std::stringstream out;
    for (int i=0;i<TABLE_SIZE;i++)
        for (Book* b=bookTable[i]; b; b=b->next)
            out << "ISBN: " << b->isbn
                << " | " << b->title
                << " | " << b->author
                << " | " << (b->available?"Yes":"No") << "\n";
    snprintf(buffer,bufSize,"%s",out.str().c_str());
}

EXPORT void issueBook(int roll, int isbn) {
    Student* s = findStudent(roll);
    Book* b = findBook(isbn);
    if (!s || !b || !b->available) return;
    b->available = false;
    b->issuedTo = roll;
    s->balance -= 2;
    saveBooks(); saveStudents();
}

EXPORT void returnBook(int roll, int isbn) {
    Book* b = findBook(isbn);
    if (!b || b->issuedTo!=roll) return;
    b->available = true;
    b->issuedTo = -1;
    saveBooks();
}