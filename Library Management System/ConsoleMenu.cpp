#include <iostream>
#include <limits>
#include "ConsoleMenu.h"

using namespace std;

ConsoleMenu::ConsoleMenu(BookService* bs, MemberService* ms, BorrowService* br, ReportService* rs)
    : bookService(bs), memberService(ms), borrowService(br), reportService(rs) {}

void ConsoleMenu::pause() {
    cout << "\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void ConsoleMenu::showMainMenu() {
    while (true) {
        cout << "\n============================\n";
        cout << "        Library Menu        \n";
        cout << "============================\n";
        cout << "1. Add Book\n";
        cout << "2. Remove Book\n";
        cout << "3. Search Book\n";
        cout << "4. List Books\n";
        cout << "5. Add Member\n";
        cout << "6. Remove Member\n";
        cout << "7. Search Member\n";
        cout << "8. List Members\n";
        cout << "9. Borrow Book\n";
        cout << "10. Return Book\n";
        cout << "11. Report: Available Books\n";
        cout << "12. Report: Borrowed Books\n";
        cout << "13. Report: Books by Category\n";
        cout << "0. Exit\n";
        cout << "============================\n";
        cout << "Enter choice: ";

        int choice;
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Try again.\n";
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1:  addBookMenu(); break;
            case 2:  removeBookMenu(); break;
            case 3:  searchBookMenu(); break;
            case 4:  listBooksMenu(); break;
            case 5:  addMemberMenu(); break;
            case 6:  removeMemberMenu(); break;
            case 7:  searchMemberMenu(); break;
            case 8:  listMembersMenu(); break;
            case 9:  borrowBookMenu(); break;
            case 10: returnBookMenu(); break;
            case 11: reportAvailableBooksMenu(); break;
            case 12: reportBorrowedBooksMenu(); break;
            case 13: reportBooksByCategoryMenu(); break;
            case 0:
                cout << "GOOD BYE :) \n";
                return;
            default:
                cout << "Invalid choice. Try again.\n";
                break;
        }
    }
}


void ConsoleMenu::addBookMenu() {}
void ConsoleMenu::removeBookMenu() {}
void ConsoleMenu::listBooksMenu() {}
void ConsoleMenu::searchBookMenu() {}
void ConsoleMenu::addMemberMenu() {}
void ConsoleMenu::removeMemberMenu() {}
void ConsoleMenu::listMembersMenu() {}
void ConsoleMenu::searchMemberMenu() {}
void ConsoleMenu::borrowBookMenu() {}
void ConsoleMenu::returnBookMenu() {}
void ConsoleMenu::reportAvailableBooksMenu() {}
void ConsoleMenu::reportBorrowedBooksMenu() {}
void ConsoleMenu::reportBooksByCategoryMenu() {}




