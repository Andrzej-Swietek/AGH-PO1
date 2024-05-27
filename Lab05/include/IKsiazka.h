#ifndef IKsiazka_h
#define IKsiazka_h

#include <string>
#include <vector>

class IKsiazka {
public:
    /*
    virtual function to get title
    */
    virtual std::string getTitle() const = 0;
    /*
    virtual function to get author name
    */
    virtual std::string getAuthor() const = 0;

    /*
    virtual function to get id
    */
    virtual int getID() const = 0;

    /*
    virtual function to get genre
    */
    virtual std::string getGenre() const = 0;


    /*
    virtual function to add rating for book
    take param new garde from usr integer
    */
    virtual void addRating(int rating) = 0;

    /*
    virtual function to get avarage rating
    */
    virtual double getAverageRating() const = 0;

    /**
     * Default destructor
    */
    virtual ~IKsiazka() {}
};

#endif /* IKsiazka_h */

