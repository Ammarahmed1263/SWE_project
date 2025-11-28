#include "BorrowRecord.h"
#include "Book.h"
#include "Member.h"
#include <ctime>
#include <string>
using namespace std;

string getCurrentDate() {
    time_t t = time(nullptr);
    tm* now = localtime(&t);

    char buf[20];
    strftime(buf, sizeof(buf), "%Y-%m-%d", now);
    return string(buf);
}

BorrowRecord::BorrowRecord(Member* member, Book* book): member(member), book(book){
    borrowDate = getCurrentDate();
    returnDate = "";
}

Book& BorrowRecord::getBook(){
    return *book;
}

Member& BorrowRecord::getMember(){
    return *member;
}

string BorrowRecord::getBorrowDate(){
    return borrowDate;
}

string BorrowRecord::getReturnDate(){
    return returnDate;
}

void BorrowRecord::markReturned(){
    returnDate = getCurrentDate();
}
