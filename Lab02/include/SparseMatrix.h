#ifndef SparseMatrix_H
#define SparseMatrix_H

#include<iostream>
#include<vector>
#include<map>


class SparseMatrix {
public:

    /**
     * @brief Default constructor
    */
    SparseMatrix(int rows, int cols);


    /**
     * @brief Movig constructor
     * @param[in] other matrix reference
    */
    SparseMatrix(const SparseMatrix &other);


    /**
     * @brief Movig constructor
     * @param[in] other matrix reference
    */
    SparseMatrix(SparseMatrix &&other);


    /** @brief Destructor
     * 
    */
    ~SparseMatrix();

    /** Move Semantics Method
     * Function Implementing moving semantics
     * @return rvalue reference to dictionary
     */
    SparseMatrix&& move();


    /**
     * Assign operator overload
     * @param index - index from which we read
     * @return
     */
    std::map<int, int*>& operator[](int index);


    /**
     * @berief method Responsible for adding new element to matrix
     * @param[in] row x coordinate
     * @param[in] col y coordinate
     * @param[in] value - new value we want to add
    */
    void insert(int row, int col, int* value);


    /**
     * @brief resets value at given coordinate
     * @param[in] row x coordinate
     * @param[in] col y coordinate
    */
    void reset(int row, int col);


    /**
     * @brief stream operator overloading
     * @param[in] os output stream reference
     * @param[in] m matrix reference
    */
    friend std::ostream& operator<<(std::ostream& os, const SparseMatrix& m) {
        try {
            for (int i = 0; i < m.rows; i++) {
                const std::map<int, int*> row = m.matrix.at(i);
                for (int j = 0; j < m.cols; j++) {
                    if (m.matrix.find(i) != m.matrix.end() && m.matrix.at(i).find(j) != m.matrix.at(i).end() ) {
                        os << *m.matrix.at(i).at(j) << " ";
                    } else {
                        os << "0 ";
                    }
                }
                os << "\n";
            }
            return os;
        } catch(...) {
            for (int i = 0; i < m.rows; i++) 
            {
                for (int j = 0; j < m.cols; j++) 
                {
                      os << "0 ";
                }
                  os << "\n";
            }
            return os;
        }

    }

private: 
    int rows=0;
    int cols=0;
    std::map<int, std::map<int, int*>> matrix;

    
};
#endif