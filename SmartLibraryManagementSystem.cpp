#include <iostream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;

// Base class for a Book
class Book {
protected:
    string title;
    string author;
    string category;
    bool isAvailable;

public:
    // Constructor to initialize book details
    Book(string t, string a, string c) : title(t), author(a), category(c), isAvailable(true) {}

    // Virtual function for displaying book information
    virtual void displayBookInfo() {
        cout << "📚 Title: " << title << ", Author: " << author << ", Category: " << category;
        cout << (isAvailable ? " [Available]" : " [Not Available]") << endl;
    }

    // Mark the book as borrowed
    void borrowBook() {
        if (isAvailable) {
            isAvailable = false;
            cout << "📚 You have successfully borrowed '" << title << "'!" << endl;
        } else {
            cout << "❌ Sorry, this book is not available for borrowing." << endl;
        }
    }

    // Mark the book as returned
    void returnBook() {
        if (!isAvailable) {
            isAvailable = true;
            cout << "📚 Thank you for returning '" << title << "'!" << endl;
        } else {
            cout << "❌ This book was not borrowed." << endl;
        }
    }

    // Getters and Setters
    bool getAvailability() {
        return isAvailable;
    }

    string getTitle() {
        return title;
    }

    string getCategory() {
        return category;
    }
};

// Derived class for a Novel (can be extended further)
class Novel : public Book {
public:
    Novel(string t, string a) : Book(t, a, "Novel") {}

    void displayBookInfo() override {
        cout << "📖 Novel - ";
        Book::displayBookInfo();
    }
};

// Derived class for a Research Paper (can be extended further)
class ResearchPaper : public Book {
public:
    ResearchPaper(string t, string a) : Book(t, a, "Research Paper") {}

    void displayBookInfo() override {
        cout << "📄 Research Paper - ";
        Book::displayBookInfo();
    }
};

// User class (base class for different users)
class User {
protected:
    string name;
    string userType;

public:
    // Constructor to initialize user details
    User(string n, string type) : name(n), userType(type) {}

    // Virtual function to borrow a book
    virtual void borrow(Book &book) {
        cout << "❌ You cannot borrow books as a " << userType << "." << endl;
    }

    // Virtual function to return a book
    virtual void returnBook(Book &book) {
        cout << "❌ You cannot return books as a " << userType << "." << endl;
    }
};

// Derived class for Student (inherits from User)
class Student : public User {
public:
    Student(string n) : User(n, "Student") {}

    void borrow(Book &book) override {
        if (book.getAvailability()) {
            book.borrowBook();
        } else {
            cout << "❌ Sorry, the book is unavailable." << endl;
        }
    }

    void returnBook(Book &book) override {
        book.returnBook();
    }
};

// Derived class for Staff (inherits from User)
class Staff : public User {
public:
    Staff(string n) : User(n, "Staff") {}

    void borrow(Book &book) override {
        if (book.getAvailability()) {
            book.borrowBook();
        } else {
            cout << "❌ Sorry, the book is unavailable." << endl;
        }
    }

    void returnBook(Book &book) override {
        book.returnBook();
    }
};

// Library Management class
class Library {
private:
    vector<Book*> books;
    vector<User*> users;

public:
    // Add a book to the library
    void addBook(Book* book) {
        books.push_back(book);
    }

    // Register a user
    void registerUser(User* user) {
        users.push_back(user);
    }

    // Display all available books in the library
    void displayAllBooks() {
        cout << "\n📚 List of Books in the Library: " << endl;
        for (auto book : books) {
            book->displayBookInfo();
        }
    }

    // Find and borrow a book by title
    void borrowBook(string title, User* user) {
        for (auto book : books) {
            if (book->getTitle() == title) {
                user->borrow(*book);
                return;
            }
        }
        cout << "❌ Book not found." << endl;
    }

    // Find and return a book by title
    void returnBook(string title, User* user) {
        for (auto book : books) {
            if (book->getTitle() == title) {
                user->returnBook(*book);
                return;
            }
        }
        cout << "❌ Book not found." << endl;
    }
};

int main() {
    // Create books
    Book* book1 = new Novel("The Great Gatsby", "F. Scott Fitzgerald");
    Book* book2 = new ResearchPaper("Quantum Computing: A New Era", "John Doe");
    
    // Create users
    User* student1 = new Student("Alice");
    User* staff1 = new Staff("Bob");
    
    // Create library
    Library library;
    
    // Add books to the library
    library.addBook(book1);
    library.addBook(book2);
    
    // Register users
    library.registerUser(student1);
    library.registerUser(staff1);

    // Display available books
    library.displayAllBooks();
    
    // Student borrows a book
    cout << "\n--- Student borrows a book ---" << endl;
    library.borrowBook("The Great Gatsby", student1);
    
    // Staff tries to borrow a book
    cout << "\n--- Staff borrows a book ---" << endl;
    library.borrowBook("Quantum Computing: A New Era", staff1);
    
    // Student returns the book
    cout << "\n--- Student returns a book ---" << endl;
    library.returnBook("The Great Gatsby", student1);

    // Cleanup: Deleting dynamically allocated objects
    delete book1;
    delete book2;
    delete student1;
    delete staff1;

    return 0;
}
