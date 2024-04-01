//
// Created by andrzej on 01.04.24.
//
#include "Library.h"


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



//void Library::borrowBook(std::string title, User &user)
//{
//    for (IKsiazka *ksiazka : _books)
//    {
//        if(ksiazka->getTitle() == title)
//        {
//            if(ksiazka->_status == 1)
//            {
//                ksiazka->_status = 0;
//                user._borrowedBooks.push_back(ksiazka);
//                std::cout << "Użytkownik " << user.getName();
//                std::cout << " wypożyczył książkę: " << title << "\n";
//                return;
//            }
//            std::cout << "Przepraszamy, książka \"" << title <<"\" jest już wypożyczona lub nie istnieje.\n";
//            return;
//            // break;
//        }
//    }
//    std::cout << "Przepraszamy, książka \"" << title <<"\" jest już wypożyczona lub nie istnieje.\n";
//}
//
//
//void Library::returnBook(std::string title, User &user)
//{
//    for (IKsiazka *ksiazka : _books)
//    {
//        if(ksiazka->_title == title && ksiazka->_status==0)
//        {
//            for (IKsiazka *borrowedKsiazka : user._borrowedBooks)
//            {
//                if(borrowedKsiazka->_title == title)
//                {
//                    // user._borrowedBooks.remove(borrowedKsiazka);
//                    ksiazka->_status = 1;
//                    std::cout << "Użytkownik " << user.getName();
//                    std::cout << " zwrócił książkę: " << title << "\n";
//                    return;
//                }
//            }
//            std::cout << "Przepraszamy, książka " << title << " nie została wypożyczona przez tego użytkownika lub nie istnieje.\n";
//            return;
//        }
//        break;
//    }
//    std::cout << "Przepraszamy, książka " << title << " nie została wypożyczona przez tego użytkownika lub nie istnieje.\n";
//
//}
//
//
//void Library::displayAllBooks() const
//{
//    std::cout << "\nLista książek w bibliotece:\n";
//    for (IKsiazka *ksiazka : _books)
//    {
//        std::cout << "Tytuł: " << ksiazka->_title << std::endl;
//        std::cout << "Autor: " << ksiazka->_author << std::endl;
//        std::cout << "Id ksiazki: " << ksiazka->_id << std::endl;
//        std::cout << "Gatunek: " << ksiazka->_genere << std::endl;
//        std::cout << "Na półce: " << ksiazka->_shelfId << std::endl;
//        std::cout << "Status: " << (ksiazka->_status == 1 ? "Dostępny" : "Niedostępny") << std::endl;
//        std::cout << std::endl;
//    }
//}