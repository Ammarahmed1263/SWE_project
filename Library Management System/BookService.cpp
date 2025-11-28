#include "BookService.h"
#include"Book.h"
using namespace std;

string BookService::addBook(string isb, string title, string author, string category,int totalCopies){

    // 1. Check if ISBN already exists
        for(Book &book:books){
            if(book.getIsbn()== isb){
                // Book exists ---> increment copies
                book.incrementCopies(totalCopies);
                return "Copies Incremented";
            }
        }
        //  Add new book in vector
        Book b(isb,title,author,category,totalCopies);
        books.push_back(b);
        return "Book added successfully";
}


string BookService::removeBook(string isbn){
    //create iterator to found the element that i need to erase
    for(auto it=books.begin();it!= books.end();it++){
        if(it->getIsbn()==isbn){
            books.erase(it);
            return "Book deleted successfully";
        }
    }
    return "Book doesn't exist";
}


//return the the same vector not copy
vector<Book>& BookService::getAllBooks() {
    return books;
}


vector<Book> BookService::searchBooks(string query){
    //new vector add the matched books
    vector<Book> Vsearch;
        for (Book &b : books) {
        if (b.getAuthor() == query ||
            b.getCategory() == query ||
            b.getTitle() == query ||
            b.getIsbn() == query)
        {
            Vsearch.push_back(b);
        }
    }
    return Vsearch;

}

Book* BookService::findBookByIsbn(string isbn) {
    for (Book &b : books) {
        if (b.getIsbn() == isbn)
            return &b;
    }
    return nullptr;
}
