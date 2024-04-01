//
// Created by andrzej on 01.04.24.
//

#ifndef AGH_PO1_IKSIAZKA_H
#define AGH_PO1_IKSIAZKA_H

class IKsiazka {
public:
    /**
     * @brief IKsiazka Destructor
     * Destructor set to default destructor
     *
     * @return no return
     */
    ~IKsiazka() = default;


    /**
     * @brief Method responsible for presenting important information about given book
     * @virtual - Pure virtual function
     * @return no return
     */
    virtual void wyswietlInformacje() = 0;


    /**
     * @brief Method responsible for retrieving title of given book
     * @virtual - pure virtual function
     * @return title field
     */
    virtual std::string getTitle() = 0;

};

#endif //AGH_PO1_IKSIAZKA_H
