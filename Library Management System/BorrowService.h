#pragma once
#include <vector>
#include "BorrowRecord.h"
#include "BookService.h"
#include "MemberService.h"
using namespace std;

class BorrowService {
private:
    vector<BorrowRecord> records;
    MemberService* memberService;
    BookService* bookService;


public:
    BorrowService(MemberService* memberService, BookService* BookService):memberService(memberService), bookService(bookService){};

    bool borrowBook(int memberID, string isbn);
    bool returnBook(int memberID, string isbn);
    vector<BorrowRecord> getAllBorrowRecords();
};
