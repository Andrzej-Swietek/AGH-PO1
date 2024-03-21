#ifndef _CALC_
#define _CALC_

#include <iostream>
#include <functional>

/**
Klasa reprezentujaca kalkulator
*/
class Calculator
{
public:
    /**
    * @default constructor 
    * value 0
    */
    Calculator();


    Calculator(int value);


    /**
    * Przeladowany operator przypisania
    * @param valuenew value
    * @return reference to object
    */
    Calculator& operator=(int value);

    /**
    * postincrementation overloading
    * @return reference to object
    */
    Calculator& operator++(int);

    /**
    * preecrementation overloading
    * @return reference to object
    */
    Calculator& operator--();

    /**
    * Multiplication operator overloading
    * @param val liczba przez ktora mnozymy
    * @return result of multiplication
    */
    int operator*(int val);

    // Calculator operator*(int multiplier, const Calculator& obj);
    friend Calculator operator*(int multiplier, Calculator& obj);

    // int operator*(int value, const Calculator& obj);
//   /**
//     * Multiplication operator overloading 2* obj
//     * @return result of multiplication
//     */
//     int operator int();


    /**
    * Function operator overloading
    * @param fun calback fucntion
    * @return its value storred in calculator
    */
    int operator()(std::function<int(int)> fun);

    /**
    * Function operator overloading
    * @return value in calucator
    */
    int operator()();
    
    
    /**
     * Function operator overloading
    * @param fun funkcja do wywolania
    * @param val dodatkowy argument do wywolywanej funkcji
    * @return zwraca wynik funkcji dla wartosci przechowywanej w kalkulatorze
    */
    int operator()(std::function<int(int,int)> fun, int val) const;

    // /**
    // * Przeladowany operator nawiasow
    // * @param fun funkcja do wywolania
    // * @param val1 pierwszy dodatkowy argument do wywolywanej funkcji
    // * @param val2 drugi dodatkowy argument do wywolywanej funkcji
    // * @return zwraca wynik funkcji dla przekazanych parametrow
    // */
    // int operator()(std::function<int(int,int)> &fun, int val1);




    /**
    * Przeladowany operator strumienia wyjscia
    * @param ostream referencja do obiektu strumienia wyjscia
    * @param calc const referencja obiektu typu calculator
    * @return rutput rstream ref
    */
    friend std::ostream& operator<<(std::ostream& stream, const Calculator& calc);

private:
    /**
    Skladowa zawierajaca wartosc przechowywana w kalkulatorze
    */
    int _value;
};

//   friend operator int() ( const Calculator& obj ) {
//     return obj._value;
//   };


#endif