#include <iostream>
#include "arrayLibrary.h"

using namespace std;

int main() {
    int choice;

    do {
        cout << "\n=== Array-Based Library System ===\n";
        cout << "1. Create Student Account\n";
        cout << "2. View Student Account\n";
        cout << "3. Deposit Amount\n";
        cout << "4. Add Book\n";
        cout << "5. View Books\n";
        cout << "6. Issue Book\n";
        cout << "7. Edit Book\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        int roll, isbn;
        double amount;

        switch (choice) {
            case 1:
                create_account();
                break;
            case 2:
                cout << "Enter student roll number: ";
                cin >> roll;
                display(roll);
                break;
            case 3:
                cout << "Enter student roll number: ";
                cin >> roll;
                cout << "Enter deposit amount: ";
                cin >> amount;
                deposit_amount(roll, amount);
                break;
            case 4:
                add_book();
                break;
            case 5:
                view_books();
                break;
            case 6:
                cout << "Enter student roll number: ";
                cin >> roll;
                issue_item(roll);
                break;
            case 7:
                edit_book();
                break;
            case 0:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
