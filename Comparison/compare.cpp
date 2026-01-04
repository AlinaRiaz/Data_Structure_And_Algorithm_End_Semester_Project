#include <iostream>
#include <chrono>
#include <string>
#include "../Array_implementation/arrayLibrary.h"  // Array-based functions
#include "../Hash_implementation/hashLibrary.h"    // Hash-based functions

using namespace std;
using namespace std::chrono;

void timeStudentFunctions() {
    cout << "\n--- Student Functions ---\n";
    cout << "Function                 Array(us)      Hash(us)\n";
    cout << "-------------------------------------------------\n";

    // CREATE 100 STUDENTS - Array
    auto start = high_resolution_clock::now();
    for(int i = 0; i < 100 && i < MAX_STUDENTS; i++) {
        students[i].roll = 100000 + i;
        students[i].balance = 100.0;
        students[i].name = "S" + to_string(i);  // std::string
    }
    auto end = high_resolution_clock::now();
    long long array_create = duration_cast<microseconds>(end - start).count();

    // CREATE 100 STUDENTS - Hash
    start = high_resolution_clock::now();
    for(int i = 0; i < 100; i++) {
        createStudent(100000 + i, "S" + to_string(i), 100.0);
    }
    end = high_resolution_clock::now();
    long long hash_create = duration_cast<microseconds>(end - start).count();

    cout << "Create 100 Students      " << array_create << "          " << hash_create << "\n";

    // SEARCH 50 STUDENTS
    start = high_resolution_clock::now();
    for(int i = 0; i < 50; i++) find_student(100000 + i);
    end = high_resolution_clock::now();
    long long array_search = duration_cast<microseconds>(end - start).count();

    start = high_resolution_clock::now();
    for(int i = 0; i < 50; i++) findStudent(100000 + i);
    end = high_resolution_clock::now();
    long long hash_search = duration_cast<microseconds>(end - start).count();

    cout << "Search 50 Students       " << array_search << "          " << hash_search << "\n";

    // DEPOSIT 50 STUDENTS
    start = high_resolution_clock::now();
    for(int i = 0; i < 50; i++) students[i].balance += 10;
    end = high_resolution_clock::now();
    long long array_deposit = duration_cast<microseconds>(end - start).count();

    start = high_resolution_clock::now();
    for(int i = 0; i < 50; i++) depositAmount(100000 + i, 10);
    end = high_resolution_clock::now();
    long long hash_deposit = duration_cast<microseconds>(end - start).count();

    cout << "Deposit 50 Students      " << array_deposit << "          " << hash_deposit << "\n";
}

void timeBookFunctions() {
    cout << "\n--- Book Functions ---\n";
    cout << "Function                 Array(us)      Hash(us)\n";
    cout << "-------------------------------------------------\n";

    // ADD 50 BOOKS - Array
    auto start = high_resolution_clock::now();
    for(int i = 0; i < 50 && i < MAX_BOOKS; i++) {
        books[i].isbn = 10000 + i;
        books[i].title = "B" + to_string(i);   // std::string
        books[i].author = "Author";
        books[i].available = true;
    }
    auto end = high_resolution_clock::now();
    long long array_add = duration_cast<microseconds>(end - start).count();

    // ADD 50 BOOKS - Hash
    start = high_resolution_clock::now();
    for(int i = 0; i < 50; i++) addBook(10000 + i, "B" + to_string(i), "Author");
    end = high_resolution_clock::now();
    long long hash_add = duration_cast<microseconds>(end - start).count();

    cout << "Add 50 Books             " << array_add << "          " << hash_add << "\n";

    // SEARCH 25 BOOKS
    start = high_resolution_clock::now();
    for(int i = 0; i < 25; i++) find_book(10000 + i);
    end = high_resolution_clock::now();
    long long array_search = duration_cast<microseconds>(end - start).count();

    start = high_resolution_clock::now();
    for(int i = 0; i < 25; i++) findBook(10000 + i);
    end = high_resolution_clock::now();
    long long hash_search = duration_cast<microseconds>(end - start).count();

    cout << "Search 25 Books          " << array_search << "          " << hash_search << "\n";
}

int main() {
    loadData(); // Load hash table data if needed
    timeStudentFunctions();
    timeBookFunctions();
    return 0;
}
