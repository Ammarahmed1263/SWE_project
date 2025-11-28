#include "BorrowService.h"
using namespace std;

const int LIMIT_BORROW_BOOK_PER_MEMBER = 3;

BorrowService::BorrowService(MemberService* memberService, BookService* bookService):memberService(memberService), bookService(bookService){};

bool BorrowService::borrowBook(int memberID, string isbn) {

    Book* book = bookService->findBookByIsbn(isbn);
    Member* member = memberService->findMemberById(memberID);


    // book or member don't exist
    if (!book || !member) return false;

    // check if there is available copies
    if (book->getAvailableCopies() == 0) return false;

    int borrowCount = 0;
    for (BorrowRecord &rec : records) {
        // book haven't returned yet
        if (rec.getMember().getId() == memberID &&
            rec.getReturnDate().empty()) {
            borrowCount++;
        }
    }

    // exceed limit
    if (borrowCount >= LIMIT_BORROW_BOOK_PER_MEMBER) return false;

    book->decrementCopies(1);

    records.push_back(BorrowRecord(member, book));

    return true;
}


bool BorrowService::returnBook(int memberID, string isbn) {

    Book* book = bookService->findBookByIsbn(isbn);
    Member* member = memberService->findMemberById(memberID);

    // the book or the member don't exist
    if (!book || !member) return false;

    for (BorrowRecord &rec : records) {
        if (rec.getBook().getIsbn() == isbn &&
            rec.getMember().getId() == memberID &&
            rec.getReturnDate().empty())
        {
            book->incrementCopies(1);
            rec.markReturned();
            return true;
        }
    }

    return false; // no active borrow found
}



vector<BorrowRecord>BorrowService::getAllBorrowRecords(){
    return records;
}
