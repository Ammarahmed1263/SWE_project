#pragma once
#include <vector>
#include "Book.h"
#include "BorrowService.h"
#include "BookService.h"

using namespace std;

class ReportService {
    BorrowService* borrowService;
    BookService* bookService;

public:
    ReportService(BorrowService* borrowService, BookService* bookService):borrowService(borrowService), bookService(bookService){};

    vector<string> getFormattedAvailableBooks();
    vector<string> getFormattedBorrowedBooks();
    vector<string> getFormattedBooksByCategory();
};
