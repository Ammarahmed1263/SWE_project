#include <iostream>
#include <limits>
#include "ConsoleMenu.h"
#include <vector>

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


void ConsoleMenu::addBookMenu() {

    string isbn, title, author, category;
    int totalCopies;
    cout << "\n=== Add New Book ===\n";

    cout << "Enter ISBN: "<<endl;
    getline(cin, isbn);

    cout << "Enter Title: "<<endl;
    getline(cin, title);

    cout << "Enter Author: "<<endl;
    getline(cin, author);

    cout << "Enter Category: "<<endl;
    getline(cin, category);

    cout << "Enter Total Copies: ";
    cin >> totalCopies;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    bool added = bookService->addBook(isbn, title, author, category, totalCopies);
    if (added)
        cout << "\nBook added successfully.\n";
    else
        cout << "\nBook already exists. Copies incremented.\n";
    pause();
}


void ConsoleMenu::removeBookMenu() {
    string isbn;

    cout << "\n=== Remove Book ===\n";
    cout << "Enter ISBN to remove: ";
    getline(cin, isbn);
    bool removed = bookService->removeBook(isbn);
    if (removed)
        cout << "Book removed successfully.\n";
    else
        cout << "Book not found!\n";
    pause();
}

void ConsoleMenu::listBooksMenu() {

    vector<Book> books = bookService->getAllBooks();
    cout << "\n=== All Books ===\n";

    if(books.empty())
         cout << "No books available.\n";
    else{
        for(Book &b:books){
             cout << " - " << b.getTitle()
                 << " | ISBN: " << b.getIsbn()
                 << " | Author: " << b.getAuthor()
                 << " | Category: " << b.getCategory()
                 << " | Total: " << b.getTotalCopies()
                 << " | Available: " << b.getAvailableCopies()
                 << "\n";
        }


    }

}

void ConsoleMenu::searchBookMenu() {

    string query;
    cout << "\n=== Search Book ===\n";
    cout << "Enter title/author/category/ISBN: ";
    getline(cin, query);
    vector<Book> books=bookService->searchBooks(query);

        if(books.empty())
         cout << "No books found.\n";
    else{
        for(Book &b:books){
             cout << " - " << b.getTitle()
                 << " | ISBN: " << b.getIsbn()
                 << " | Author: " << b.getAuthor()
                 << " | Category: " << b.getCategory()
                 << " | Total: " << b.getTotalCopies()
                 << " | Available: " << b.getAvailableCopies()
                 << "\n";
        }
    }
    pause();
}


void ConsoleMenu::addMemberMenu() {
     string name ,email;
     cout << "\n=== Add New Member ===\n";
     cout<<"Enter Name:\n";
     getline(cin,name);
     cout<<"Enter the Email:\n";
     getline(cin,email);
     bool added = memberService->addMember(name,email);
    if (added)
        cout << "\nMember added successfully.\n";
    else
        cout << "\nMember already exists (email must be unique).\n";
    pause();
}


void ConsoleMenu::removeMemberMenu() {

    cout << "\n=== Remove Member ===\n";
    int id;
    cout << "Enter Member ID to remove: ";
    cin >> id;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    bool deleted=memberService->removeMember(id);

    if (deleted)
        cout << "\nMember removed successfully.\n";
    else
        cout << "\nMember not found!\n";
    pause();
}


void ConsoleMenu::listMembersMenu() {

    cout << "\n=== List of All Members ===\n";

    vector<Member> all=memberService->getAllMembers();

     if (all.empty()) {
        cout << "No members found.\n";
        pause();
        return;
    }

    for ( Member& m : all) {
        cout << "------------------------------\n";
        cout << "ID: " << m.getId() << "\n";
        cout << "Name: " << m.getName() << "\n";
        cout << "Email: " << m.getEmail() << "\n";
    }

    cout << "------------------------------\n";
    pause();

}



void ConsoleMenu::searchMemberMenu() {
     cout << "\n=== Search Member ===\n";

      string query;
    cout << "Enter name, email, or ID: ";
    getline(cin, query);

    vector<Member> results = memberService->searchMembers(query);

    if (results.empty()) {
        cout << "\nNo members found.\n";
        pause();
        return;
    }

    cout << "\n=== Search Results ===\n";
    for ( Member& m : results) {
        cout << "------------------------------\n";
        cout << "ID: " << m.getId() << "\n";
        cout << "Name: " << m.getName() << "\n";
        cout << "Email: " << m.getEmail() << "\n";
    }

    cout << "------------------------------\n";
    pause();
}


void ConsoleMenu::borrowBookMenu() {
    cout << "\n====== Borrow Book ======\n";

    int memberId;
    string isbn;

    cout << "Enter Member ID: ";
    cin >> memberId;

    cout << "Enter Book ISBN: ";
    cin >> isbn;

    bool success = borrowService->borrowBook(memberId, isbn);

    if (success) {
        cout << "Book borrowed successfully!\n";
    } else {
        cout << "Borrow failed. Possible reasons:\n";
        cout << " - Member does not exist\n";
        cout << " - Book does not exist\n";
        cout << " - No available copies\n";
        cout << " - Member exceeded borrowing limit\n";
    }
    pause();
}

void ConsoleMenu::returnBookMenu() {
    cout << "\n====== Return Book ======\n";

    int memberId;
    string isbn;

    cout << "Enter Member ID: ";
    cin >> memberId;

    cout << "Enter Book ISBN: ";
    cin >> isbn;

    bool success = borrowService->returnBook(memberId, isbn);

    if (success) {
        cout << "Book returned successfully!\n";
    } else {
        cout << "Return failed. Possible reasons:\n";
        cout << " - Member does not exist\n";
        cout << " - Book does not exist\n";
        cout << " - The member did NOT borrow this book\n";
    }
    pause();
}


void ConsoleMenu::reportAvailableBooksMenu() {
    vector<string> books = reportService->getFormattedAvailableBooks();
    if (books.empty()) {
        cout << "No available books found.\n";
    } else {
        cout << "\n====== Available Books ======\n";
        for (auto& line : books) {
            cout << line << "\n";
        }
    }
    pause();
}

void ConsoleMenu::reportBorrowedBooksMenu() {
    vector<string> records = reportService->getFormattedBorrowedBooks();
    if (records.empty()) {
        cout << "No borrow records found.\n";
    } else {
        cout << "\n====== Borrow Records ======\n";
        for (auto& line : records) {
            cout << line << "\n";
        }
    }
    pause();
}

void ConsoleMenu::reportBooksByCategoryMenu() {
    vector<string> formatted = reportService->getFormattedBooksByCategory();
    if (formatted.empty()) {
        cout << "No books found.\n";
    } else {
        cout << "\n====== Books by Category ======\n";
        for (auto& line : formatted) {
            cout << line << "\n";
        }
    }
    pause();
}




