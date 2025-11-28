#pragma once
#include <vector>
#include <string>
#include "Book.h"
using namespace std;

class BookService {
private:
    vector<Book> books;

public:
    BookService() = default;

    bool addBook(string isb, string title, string author, string category,  int totalCopies );
    bool removeBook(string isbn);

    vector<Book> &getAllBooks();
    vector<Book> searchBooks(string query);
};
