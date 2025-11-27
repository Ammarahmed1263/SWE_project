#include <iostream>
using namespace std;

#include "BookService.h"
#include "MemberService.h"
#include "BorrowService.h"
#include "ReportService.h"
#include "ConsoleMenu.h"

int main() {
    BookService bookService;
    MemberService memberService;

    BorrowService borrowService(&memberService, &bookService);

    ReportService reportService(&borrowService, &bookService);

    ConsoleMenu menu(
        &bookService,
        &memberService,
        &borrowService,
        &reportService
    );

    menu.showMainMenu();

    return 0;
}
