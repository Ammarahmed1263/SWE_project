# Library Management System — Test Cases (15 Scenarios)

## Notes
- System: C++ console app using in-memory services (`BookService`, `MemberService`, `BorrowService`, `ReportService`).
- Entry point via `ConsoleMenu`. Borrow limit is 3 active books per member.
- Tests are scenario-based, not automated; intended for manual validation or as specs for future automation.
- IDs `TC-01..TC-10` are functional; `NFR-01..NFR-05` are non-functional.

---

## Functional Test Cases (10)

### TC-01: Add Book (new ISBN)
- Area: `BookService.addBook`
- Preconditions: Catalog is empty.
- Steps:
  1. Add book: ISBN="111", Title="Clean Code", Author="Robert C. Martin", Category="Programming", TotalCopies=5.
- Expected:
  - Returns `true` (added).
  - Book appears with Total=5, Available=5 in list.

### TC-02: Add Book (duplicate increments copies)
- Area: `BookService.addBook`
- Preconditions: Book with ISBN "111", Total=5 exists.
- Steps:
  1. Add same ISBN "111" again with any title/author/category, TotalCopies=2.
- Expected:
  - Returns `false` (already exists).
  - Existing book Total increases to 7, Available increases to 7.

### TC-03: Remove Book (existing)
- Area: `BookService.removeBook`
- Preconditions: Book with ISBN "111" exists.
- Steps:
  1. Remove book ISBN "111".
- Expected:
  - Returns `true`.
  - Book no longer appears in list.

### TC-04: Remove Book (non-existent)
- Area: `BookService.removeBook`
- Preconditions: No book with ISBN "999".
- Steps:
  1. Remove book ISBN "999".
- Expected:
  - Returns `false`.
  - Catalog unchanged.

### TC-05: Search Book by fields
- Area: `BookService.searchBooks`
- Preconditions: Add 3 books:
  - (A) ISBN="200", Title="Intro to C++", Author="Bjarne", Category="Programming", Copies=3
  - (B) ISBN="201", Title="C++ Templates", Author="Alexandrescu", Category="Programming", Copies=2
  - (C) ISBN="300", Title="Cooking 101", Author="Jane Doe", Category="Cooking", Copies=4
- Steps:
  1. Search query "C++"
  2. Search query "Cooking"
  3. Search query "201" (ISBN)
- Expected:
  - (1) returns A and B
  - (2) returns C
  - (3) returns B only

### TC-06: Add Member (new)
- Area: `MemberService.addMember`
- Preconditions: No existing member with email "user1@example.com".
- Steps:
  1. Add member Name="User One", Email="user1@example.com".
- Expected:
  - Returns `true`.
  - Member gets a generated ID (positive int) and is listable.

### TC-07: Add Member (duplicate email)
- Area: `MemberService.addMember`
- Preconditions: Member with Email "user1@example.com" exists.
- Steps:
  1. Add another member with Email="user1@example.com".
- Expected:
  - Returns `false` (email must be unique).
  - Members list unchanged.

### TC-08: Borrow Book (happy path)
- Area: `BorrowService.borrowBook`
- Preconditions:
  - Member M (ID=m1) exists.
  - Book B (ISBN="200") exists with AvailableCopies >= 1.
- Steps:
  1. `borrowBook(m1, "200")`.
- Expected:
  - Returns `true`.
  - Book.available decremented by 1.
  - A new `BorrowRecord` is added with empty `ReturnDate`.

### TC-09: Borrow Book (no available copies)
- Area: `BorrowService.borrowBook`
- Preconditions:
  - Member M (ID=m1) exists.
  - Book B (ISBN="201") exists with AvailableCopies = 0.
- Steps:
  1. `borrowBook(m1, "201")`.
- Expected:
  - Returns `false`.
  - No change in records or copies.

### TC-10: Return Book (not borrowed)
- Area: `BorrowService.returnBook`
- Preconditions:
  - Member M (ID=m2) exists.
  - Book B (ISBN="300") exists.
  - Member m2 has no active borrow for ISBN "300".
- Steps:
  1. `returnBook(m2, "300")`.
- Expected:
  - Returns `false`.
  - No change in records or copies.

#### Additional Functional Variants (optional if expanding)
- Borrow Book with non-existent member → `false`.
- Borrow Book with non-existent book → `false`.
- Borrow limit enforcement: after 3 active borrows, 4th attempt → `false`.
- Successful return increments available copies by 1 and sets `ReturnDate`.

---

## Non-Functional Test Cases (5)

### NFR-01: Performance — Search under large catalog
- Goal: Search responsiveness.
- Setup: Add 10,000 books (mixed titles/categories), no printing during add.
- Steps:
  1. Call `searchBooks("C++")` 100 times (no console printing of results, just count).
- Expected:
  - Average search completes under 150 ms on a typical dev machine.
  - No excessive CPU spikes (>80% sustained) during the loop.

### NFR-02: Performance — List available books formatting
- Goal: Reporting throughput without UI lag.
- Setup: 5,000 books with varying availability.
- Steps:
  1. Call `reportService.getFormattedAvailableBooks()`.
- Expected:
  - Returns within 2 seconds.
  - Memory usage remains stable (no runaway growth across repeated calls).

### NFR-03: Robustness — Boundary-length strings
- Goal: Handle long inputs safely.
- Setup: Add a book with Title=1,024 chars, Author=512 chars, Category=256 chars; regular ISBN.
- Steps:
  1. Add the book, then search by a unique long substring.
- Expected:
  - No crashes or truncation that breaks search.
  - Book fields retained exactly as provided.

### NFR-04: Reliability — Borrow/Return stability under repetition
- Goal: No state drift across cycles.
- Setup: Member M, Book B with Total=Available=5.
- Steps:
  1. Repeat 1,000 times: `borrowBook(M, B)`, then `returnBook(M, B)`.
- Expected:
  - All borrow operations succeed; all return operations succeed.
  - Final Available equals initial (5). No leaked/duplicate records beyond expected history.

### NFR-05: Usability — Clear prompts and error messaging
- Goal: Clear user guidance in `ConsoleMenu`.
- Setup: Run the menu interactively.
- Steps:
  1. Trigger borrow flow and enter a valid member ID but wrong ISBN.
  2. Trigger borrow flow and enter a non-existent member ID.
  3. Trigger return flow for a book not borrowed.
- Expected:
  - Messages match current implementation (generic failure reasons listed).
  - Prompts are understandable and consistently formatted. No ambiguous or missing prompts.

---

## Data Sets and IDs (example values)
- Members:
  - m1: Name="User One", Email="user1@example.com"
  - m2: Name="User Two", Email="user2@example.com"
- Books:
  - ISBN 200: "Intro to C++"
  - ISBN 201: "C++ Templates"
  - ISBN 300: "Cooking 101"

---

## Coverage Map (high-level)
- `BookService`: add, remove, search, getAll
- `MemberService`: add, remove, find, search, list
- `BorrowService`: borrow (copies/limit/lookup checks), return (matching active record), getAllBorrowRecords
- `ConsoleMenu`: input/output flows, failure messaging
