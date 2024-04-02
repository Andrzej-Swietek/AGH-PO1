//
// Created by andrzej on 01.04.24.
//

#include "Library.h"

Library::Library() = default;


Library::Library(const std::vector<IKsiazka*>& booksVector)
        : books(booksVector)
{
}

Library::~Library()
{
    for (IKsiazka *ksiazka : books)
    {
        delete ksiazka;
    }
}


void Library::addMaterial(IKsiazka *material)
{
    books.push_back(material);
}


bool Library::removeMaterial(const std::string& title) {
    auto it = std::find_if(books.begin(), books.end(), [&title](const IKsiazka* book)->bool {
        return book->title == title;
    });

    if (it != books.end()) {
        delete *it;
        books.erase(it);
        return true;
    }

    return false;
}


void Library::borrowBook(std::string title, User &user)
{
    for (IKsiazka* ksiazka : books) {
        if (ksiazka->getTitle() == title) {
            if ( !ksiazka->getAvailability() ) {
                std::cout << "Przepraszamy, książka \"" << title << "\" jest już wypożyczona.\n"; return;
            }

            ksiazka->setAvailability(false);
            user.borrowBook(ksiazka);
            std::cout << "Użytkownik " << user.getName() << " wypożyczył książkę: " << title << "\n";
            return;
        }
    }

    std::cout << "Przepraszamy, książka \"" << title << "\" nie istnieje w bibliotece.\n";
}


void Library::returnBook(std::string title, User &user)
{
    for (IKsiazka *ksiazka : books) {
        if( ksiazka->getTitle() == title && !ksiazka->getAvailability() ) {
            ReturnBookResult result = user.returnBook(title);
            std::cout << result.message << std::endl;
            return;
        }
    }

    std::cout << "Przepraszamy, książka " << title << " nie została wypożyczona przez tego użytkownika lub nie istnieje.\n";
}


void Library::displayAllBooks() const
{
    std::cout << "\nLista książek w bibliotece:\n";
    for (IKsiazka *ksiazka : books)
    {
        std::cout << "Tytuł: " << ksiazka->title << std::endl;
        std::cout << "Autor: " << ksiazka->author << std::endl;
        std::cout << "Id ksiazki: " << ksiazka->id << std::endl;
        std::cout << "Gatunek: " << ksiazka->genre << std::endl;
        std::cout << "Na półce: " << ksiazka->getShelfId() << std::endl;
        std::cout << "Status: " << (ksiazka->getAvailability() ? "Dostępny" : "Niedostępny") << std::endl;
        std::cout << std::endl;
    }
}

void Library::moveBookToShelf(std::string title, int newShelfId) {
    for (IKsiazka* ksiazka : books) {
        if (ksiazka->getTitle() == title) {
            ksiazka->setShelfId(newShelfId);
            std::cout << "Książka \"" << title << "\" została przeniesiona na półkę o numerze: " << newShelfId << "\n";
            return;
        }
    }
    std::cout << "Przepraszamy, książka \"" << title << "\" nie została znaleziona w bibliotece.\n";
}


void Library::swapBooks(std::string title1, std::string title2) {
    IKsiazka* book1 = nullptr;
    IKsiazka* book2 = nullptr;

    for (IKsiazka* ksiazka : books) {
        if (ksiazka->getTitle() == title1) {
            book1 = ksiazka;
        }
        if (ksiazka->getTitle() == title2) {
            book2 = ksiazka;
        }
    }

    if (book1 && book2) {
        int tempShelfId = book1->getShelfId();
        book1->setShelfId(book2->getShelfId());
        book2->setShelfId(tempShelfId);
        std::cout << "Książki \"" << title1 << "\" i \"" << title2 << "\" zostały zamienione na półkach.\n";
    } else {
        std::cout << "Przepraszamy, jedna z książek nie została znaleziona w bibliotece.\n";
    }
}


void Library::displayBorrowedBooks() const {
    std::cout << "Borrowed Books:\n";
    for (const IKsiazka* book : books) {
        if (!book->getAvailability()) {
            std::cout << "Title: " << book->title << "\n";
        }
    }
}


std::vector<IKsiazka*> Library::sortByTitle() const {
    std::vector<IKsiazka*> sortedBooks = books;
    std::sort(sortedBooks.begin(), sortedBooks.end(), [](const IKsiazka* a, const IKsiazka* b)->bool {
        return a->title < b->title;
    });
    return sortedBooks;
}


std::vector<IKsiazka*> Library::sortById() const {
    std::vector<IKsiazka*> sortedBooks = books;
    std::sort(sortedBooks.begin(), sortedBooks.end(), [](const IKsiazka* a, const IKsiazka* b)->bool {
        return a->id < b->id;
    });
    return sortedBooks;
}

// Operator overloading
IKsiazka* Library::operator[](const std::string title) const {
    for (IKsiazka* ksiazka : books) {
        if (ksiazka->getTitle() == title) {
            return ksiazka;
        }
    }
    return nullptr; // Book not found
}

IKsiazka* Library::operator[](int id) const {
    for (IKsiazka* ksiazka : books) {
        if (ksiazka->id == id) {
            return ksiazka;
        }
    }
    return nullptr;
}


///  ======================= Aggregations  ========================


std::unordered_map<std::string, std::vector<IKsiazka*>> Library::groupBy(std::function<std::string(const IKsiazka*)> groupFunction) const {
    std::unordered_map<std::string, std::vector<IKsiazka*>> groupedBooks;
    for (IKsiazka* ksiazka : books) {
        std::string groupKey = groupFunction(ksiazka);
        groupedBooks[groupKey].push_back(ksiazka);
    }
    return groupedBooks;
}


std::unordered_map<std::string, std::vector<IKsiazka*>> Library::booksByGenre() const {
    auto groupByGenre = [](const IKsiazka* book) -> std::string {
        return book->genre;
    };
    this->groupBy(groupByGenre);
}


std::unordered_map<std::string, std::vector<IKsiazka*>> Library::booksByAuthor() const {
    auto groupByAuthor = [](const IKsiazka* book) -> std::string {
        return book->author;
    };
    this->groupBy(groupByAuthor);
}


std::unordered_map<std::string, std::vector<IKsiazka*>> Library::booksByAvailability() const {
    auto groupByAvailability = [](const IKsiazka* book) -> std::string {
        return book->available ? "available" : "unavailable";
    };
    this->groupBy(groupByAvailability);
}


std::unordered_map<std::string, std::vector<IKsiazka*>> Library::groupBy(const std::string& groupCriteria) const {
    if (groupCriteria == "author") {
        return this->booksByAuthor();
    } else if (groupCriteria == "genre") {
        return this->booksByGenre();
    } else if (groupCriteria == "availability") {
        return this->booksByAvailability();
    } else {
        std::cerr << "Invalid group criteria specified: " << groupCriteria << std::endl;
        return {};
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////