# Requirements

## 1\. **Project Overview**
The Library Management System (LMS) is a console-based application to manage books, members, borrowing/returning operations, and reports in a library.
It should allow features to be easily added in the future.
**Goals:**
*   Support multiple copies of books
*   Allow librarians to manage books and members
*   Track borrow/return operations
*   Generate basic reports
* * *
## 2\. **Functional Requirements**
### 2.1 **Book Management**
*   **Add Book:** Add a book with title, author, ISBN, category, and copies. If the ISBN exists, increment copies.
*   **Remove Book:** Remove a book only if all copies are available.
*   **Search Books:** Search by title, author, or category.
*   **List Books:** View all books with available copies.
### 2.2 **Member Management**
*   **Add Member:** Register a new member with name, ID, and email. Member ID must be unique.
*   **Remove Member:** Remove the member only if all borrowed books are returned.
*   **Search Members:** Search by name or member ID.
*   **List Members:** View all registered members.
### 2.3 **Borrow & Return**
*   **Borrow Book:** A member can borrow a book only if at least one copy is available. Borrowing must be processed by the librarian. Decreases available copies. Creates a borrow record. Members can only borrow up to 3 books.
*   **Return Book:** Member returns a book. Increases available copies. Mark's borrowed record returned.
*   
### 2.4 **Reports**
*   **Available Books Report:** Show all books with copies available.
*   **Borrowed Books Report:** Show all borrowed books and borrower info.
*   **Books by Category Report:** Show all books grouped by category.
### 2.5 **Startup / Menu Navigation**
*   The main menu allows navigation to Book, Member, Borrow/Return, and Reports.
*   Back option returns to the main menu.
* * *
## 3\. **Non-Functional Requirements**
*   **Platform:** Console application Windows
*   **Performance:** Handle at least 1000 books and 500 members without lag
*   **Usability:** Simple menu-based interface, no GUI needed initially