#pragma once
#include <string>
#include "MemberService.h"
#include "BookService.h"
#include "BorrowService.h"
#include "ReportService.h"
using namespace std;



class ConsoleMenu {
private:
    BookService* bookService;
    MemberService* memberService;
    BorrowService* borrowService;
    ReportService* reportService;

    void pause();

public:
    ConsoleMenu(BookService* bs, MemberService* ms, BorrowService* br, ReportService* rs);

    void showMainMenu();

    void addBookMenu();
    void removeBookMenu();
    void searchBookMenu();
    void listBooksMenu();

    void addMemberMenu();
    void removeMemberMenu();
    void searchMemberMenu();
    void listMembersMenu();

    void borrowBookMenu();
    void returnBookMenu();

    void reportAvailableBooksMenu();
    void reportBorrowedBooksMenu();
    void reportBooksByCategoryMenu();
};
