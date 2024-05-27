#include <iostream>
#include <vector>
#include <map>

class SparseMatrix {
private:
    std::map<int, std::map<int, int*>> matrix;
    int rows;
    int cols;

public:
    SparseMatrix(int rows, int cols) : rows(rows), cols(cols) {}

    void insert(int row, int col, int* value) {
        if (row >= 0 && row < rows && col >= 0 && col < cols) {
            matrix[row][col] = value;
        }
    }

    std::map<int, int*>& operator[](int index) {
        return matrix[index];
    }

    void reset(int row, int col) {
        if (matrix.find(row) != matrix.end() && matrix[row].find(col) != matrix[row].end()) {
            delete matrix[row][col];
            matrix[row].erase(col);
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const SparseMatrix& matrix) {
        for (int i = 0; i < matrix.rows; ++i) {
            for (int j = 0; j < matrix.cols; ++j) {
                if (matrix.matrix.find(i) != matrix.matrix.end() && matrix.matrix[i].find(j) != matrix.matrix[i].end()) {
                    os << *matrix.matrix.at(i).at(j) << " ";
                } else {
                    os << "0 ";
                }
            }
            os << "\n";
        }
        return os;
    }
};
