#include "SparseMatrix.h"

 
SparseMatrix::SparseMatrix(int rows, int cols)
{
    this->rows = rows;
    this->cols = cols;
}

SparseMatrix::~SparseMatrix()
{
}

SparseMatrix::SparseMatrix(const SparseMatrix &other): matrix(std::move(other.matrix))
{
    this->rows = other.rows;
    this->cols = other.cols;
}

SparseMatrix::SparseMatrix(SparseMatrix &&other): matrix(std::move(other.matrix)) {
    this->rows = other.rows;
    this->cols = other.cols;
}


SparseMatrix&& SparseMatrix::move()
{
    return std::move(*this);
}


std::map<int, int*>& SparseMatrix::operator[](int index) {
    return matrix[index];
}

    
void SparseMatrix::insert(int row, int col, int* value)
{
    if (row >= 0 && row < rows && col >= 0 && col < cols) {
        matrix[row][col] = value;
    }
}


void SparseMatrix::reset(int row, int col)
{
    if (matrix.find(row) != matrix.end() && matrix[row].find(col) != matrix[row].end()) {
        delete matrix[row][col];
        matrix[row].erase(col);
    }
}