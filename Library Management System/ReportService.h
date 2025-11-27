#pragma once
#include <vector>
#include <map>
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
    map<string, vector<Book>> getBooksByCategory();
};
