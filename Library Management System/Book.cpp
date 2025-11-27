#include "Book.h"
using namespace std;

Book::Book(string isbn, string title, string author, string category, int totalCopies):isbn(isbn),title(title),author(author),category(category)
,availableCopies(totalCopies),totalCopies(totalCopies){}

//Getters
string Book::getIsbn(){return isbn;}
string Book::getTitle(){return title;}
string Book::getAuthor(){return author;}
string Book::getCategory(){return category;}
int Book::getTotalCopies(){return totalCopies;}
int Book::getAvailableCopies(){return availableCopies;}

//decrementCopies
void Book::decrementCopies(int amount){availableCopies-=amount;}

//incrementCopies
void Book::incrementCopies(int amount){availableCopies+=amount;totalCopies+=amount;}
