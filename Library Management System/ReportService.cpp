#include "ReportService.h"
#include <map>
#include <sstream>

vector<string> ReportService::getFormattedAvailableBooks() {
    vector<string> result;
    for (Book& b : bookService->getAllBooks()) {
        if (b.getAvailableCopies() > 0) {
            stringstream ss;
            ss << "ISBN: " << b.getIsbn()
               << " | Title: " << b.getTitle()
               << " | Author: " << b.getAuthor()
               << " | Category: " << b.getCategory()
               << " | Available: " << b.getAvailableCopies();
            result.push_back(ss.str());
        }
    }
    return result;
}

vector<string> ReportService::getFormattedBorrowedBooks() {
    vector<string> result;
    for (BorrowRecord& rec : borrowService->getAllBorrowRecords()) {
        Book& b = rec.getBook();
        Member& m = rec.getMember();
        string returnDate = rec.getReturnDate().empty() ? "Not Returned" : rec.getReturnDate();

        stringstream ss;
        ss << "ISBN: " << b.getIsbn()
           << " | Title: " << b.getTitle()
           << " | Borrowed by: " << m.getName()
           << " | Member ID: " << m.getId()
           << " | Borrow Date: " << rec.getBorrowDate()
           << " | Return Date: " << returnDate;
        result.push_back(ss.str());
    }
    return result;
}

vector<string> ReportService::getFormattedBooksByCategory() {
    map<string, vector<Book>> tempMap;
    for (Book& b : bookService->getAllBooks()) {
        tempMap[b.getCategory()].push_back(b);
    }

    vector<string> result;
    for (auto& [category, books] : tempMap) {
        result.push_back("Category: " + category);
        for (Book& b : books) {
            stringstream ss;
            ss << "    ISBN: " << b.getIsbn()
               << " | Title: " << b.getTitle()
               << " | Author: " << b.getAuthor()
               << " | Total Copies: " << b.getTotalCopies()
               << " | Available: " << b.getAvailableCopies();
            result.push_back(ss.str());
        }
    }
    return result;
}
