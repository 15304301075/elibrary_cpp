#include <iostream>
#include <string>
#include <vector>


// 基类1：Book
class Book {
protected:
    std::string title;
    std::string author;
    int year;
    bool isBorrowed;

public:
    Book(const std::string& title, const std::string& author, int year)
        : title(title), author(author), year(year), isBorrowed(false) {}

    // 借阅书籍
    virtual void borrow() {
        if (isBorrowed) {
            std::cout << title << " is already borrowed.\n";
        } else {
            isBorrowed = true;
            std::cout << title << " has been borrowed.\n";
        }
    }

    // 归还书籍
    virtual void returnBook() {
        if (isBorrowed) {
            isBorrowed = false;
            std::cout << title << " has been returned.\n";
        } else {
            std::cout << title << " is not borrowed.\n";
        }
    }

    // 显示书籍信息
    virtual void display() const {
        std::cout << "Title: " << title << "\n";
        std::cout << "Author: " << author << "\n";
        std::cout << "Year: " << year << "\n";
        std::cout << "Status: " << (isBorrowed ? "Borrowed" : "Available") << "\n";
    }

    // 虚析构函数
    virtual ~Book() {}
};

// 派生类：Novel
class Novel : public Book {
private:
    std::string genre;

public:
    Novel(const std::string& title, const std::string& author, int year, const std::string& genre)
        : Book(title, author, year), genre(genre) {}

    void display() const override {
        std::cout << "Type: Novel\n";
        Book::display();
        std::cout << "Genre: " << genre << "\n";
    }
};

// 派生类：Textbook
class Textbook : public Book {
private:
    std::string subject;

public:
    Textbook(const std::string& title, const std::string& author, int year, const std::string& subject)
        : Book(title, author, year), subject(subject) {}

    void display() const override {
        std::cout << "Type: Textbook\n";
        Book::display();
        std::cout << "Subject: " << subject << "\n";
    }
};

// 派生类：Magazine
class Magazine : public Book {
private:
    int issueNumber;

public:
    Magazine(const std::string& title, const std::string& author, int year, int issueNumber)
        : Book(title, author, year), issueNumber(issueNumber) {}

    void display() const override {
        std::cout << "Type: Magazine\n";
        Book::display();
        std::cout << "Issue Number: " << issueNumber << "\n";
    }
};

int main() {
    // 创建图书馆中的书籍
    Novel novel("The Great Gatsby", "F. Scott Fitzgerald", 1925, "Fiction");
    Textbook textbook("Introduction to Algorithms", "Thomas H. Cormen", 2009, "Computer Science");
    Magazine magazine("National Geographic", "Various Authors", 2023, 256);

    // 使用基类指针管理书籍
    std::vector<Book*> library;
    library.push_back(&novel);
    library.push_back(&textbook);
    library.push_back(&magazine);

    // 遍历图书馆，显示书籍信息
    for (const auto& book : library) {
        book->display();
        std::cout << "\n";
    }

    // 借阅和归还书籍
    novel.borrow();
    textbook.borrow();
    textbook.returnBook();
    magazine.borrow();

    return 0;
}




















