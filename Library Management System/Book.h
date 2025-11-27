#pragma once
#include <string>
using namespace std;

class Book {
private:
    string isbn;
    string title;
    string author;
    string category;
    int totalCopies;
    int availableCopies;

public:
    Book(string isbn, string title, string author, string category, int totalCopies);

    string getIsbn();
    string getTitle();
    string getAuthor();
    string getCategory();
    int getTotalCopies();
    int getAvailableCopies();

    void decrementCopies(int amount);
    void incrementCopies(int amount);
};
