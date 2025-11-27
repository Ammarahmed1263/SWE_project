#include "BookService.h"
#include"Book.h"
using namespace std;

bool BookService::addBook(string isb, string title, string author, string category,int totalCopies){

    // 1. Check if ISBN already exists
        for(Book &book:books){
            if(book.getIsbn()== isb){
                // Book exists ---> increment copies
                book.incrementCopies(totalCopies);
                return true;
            }
        }
        //  Add new book in vector
        Book b(isb,title,author,category,totalCopies);
        books.push_back(b);
        return true;
}


bool BookService::removeBook(string isbn){
    //create iterator to found the element that i need to erase
    for(auto it=books.begin();it!= books.end();it++){
        if(it->getIsbn()==isbn){
            books.erase(it);
            return true;
        }
    }
    return false;
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
