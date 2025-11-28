#include "BorrowService.h"
using namespace std;

const int LIMIT_BORROW_BOOK_PER_MEMBER = 3;

BorrowService::BorrowService(MemberService* memberService, BookService* bookService):memberService(memberService), bookService(bookService){};

string BorrowService::borrowBook(int memberID, string isbn) {

    Book* book = bookService->findBookByIsbn(isbn);
    Member* member = memberService->findMemberById(memberID);


    // book or member don't exist
    if (!book || !member) return "Book or Member not found";

    // check if there is available copies
    if (book->getAvailableCopies() == 0) return "No available Copies";

    int borrowCount = 0;
    for (BorrowRecord &rec : records) {
        // book haven't returned yet
        if (rec.getMember().getId() == memberID &&
            rec.getReturnDate().empty()) {
            borrowCount++;
        }
    }

    // exceed limit
    if (borrowCount >= LIMIT_BORROW_BOOK_PER_MEMBER) return "Borrow limit exceeded";

    book->decrementCopies(1);

    records.push_back(BorrowRecord(member, book));

    return "Book borrowed successfully";
}


string BorrowService::returnBook(int memberID, string isbn) {

    Book* book = bookService->findBookByIsbn(isbn);
    Member* member = memberService->findMemberById(memberID);

    // the book or the member don't exist
    if (!book || !member) return "Book or Member not found";

    for (BorrowRecord &rec : records) {
        if (rec.getBook().getIsbn() == isbn &&
            rec.getMember().getId() == memberID &&
            rec.getReturnDate().empty())
        {
            book->incrementCopies(1);
            rec.markReturned();
            return "Book Returned successfully";
        }
    }

    return "The member did NOT borrow this book"; // no active borrow found
}



vector<BorrowRecord>BorrowService::getAllBorrowRecords(){
    return records;
}
