#pragma once
#include <string>
#include "Book.h"
#include "Member.h"
using namespace std;

class BorrowRecord {
private:
    Member* member;
    Book* book;
    string borrowDate;
    string returnDate;

public:
    BorrowRecord(Member* member, Book* book);

    Member& getMember();
    Book& getBook();
    string getBorrowDate();
    string getReturnDate();

    void markReturned();
};
