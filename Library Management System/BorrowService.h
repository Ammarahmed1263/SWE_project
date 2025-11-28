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
    BorrowService(MemberService* memberService, BookService* BookService);

    string borrowBook(int memberID, string isbn);
    string returnBook(int memberID, string isbn);
    vector<BorrowRecord> getAllBorrowRecords();
};
