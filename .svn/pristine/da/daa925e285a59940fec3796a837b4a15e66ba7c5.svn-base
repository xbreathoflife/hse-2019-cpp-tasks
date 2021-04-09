#include <fstream>
#include "matrix.h"

Matrix::Matrix(int rows_, int cols_) : rows(rows_), cols(cols_) {}

Matrix::~Matrix() {}

void Matrix::resize(int rows_, int cols_) {
    matrix.resize(rows_);
    for (int i = 0; i < rows_; ++i)
        matrix[i].resize(cols_);
    rows = rows_;
    cols = cols_;
}

void Matrix::add(const Matrix& other) {
    if (cols != other.cols || rows != other.rows)
        throw MatrixException("ADD: dimensions do not match.");
    for (int row_i = 0; row_i < rows; row_i++) {
        for (int col_i = 0; col_i < cols; col_i++)
            matrix[row_i][col_i] += other.matrix[row_i][col_i];
    }
}

void Matrix::mul(const Matrix& other) {
    if (cols != other.rows)
        throw MatrixException("MUL: #arg1.columns != #arg2.rows.");
    try {
        resize(rows, other.cols);
        std::vector<std::vector<int> > res(rows, std::vector<int> (cols, 0));
        for (int row_i = 0; row_i < rows; row_i++) {
            for (int col_i = 0; col_i < cols; col_i++)
                for (int i = 0; i < other.rows; i++)
                    res[row_i][col_i] += matrix[row_i][i] * other.matrix[i][col_i];
        }
        matrix = res;
    } catch(const std::bad_alloc&) {
        std::cout << "Unable to allocate memory." << std::endl;
    }  
}

int Matrix::get(int row, int col) const {
    if (row < 0 || row >= rows || col < 0 || col >= cols)
        throw MatrixException("ACCESS: bad index.");
    return matrix[row][col];
}

void Matrix::set(int row, int col, int val) {
    matrix[row][col] = val;
}

void Matrix::read(std::string filename) {
    std::ifstream file(filename);
    if (!file)
        throw FileException("LOAD: unable to open file.");
    int rows, cols, value;
    if (file.eof())
        throw FileException("LOAD: invalid file format.");
    file >> rows;
    if (file.eof())
        throw FileException("LOAD: invalid file format.");
    file >> cols;
    if (file.eof())
        throw FileException("LOAD: invalid file format.");
    Matrix other;
    try {
        other.resize(rows, cols);
        for (int row_i = 0; row_i < rows; row_i++) {
            for (int col_i = 0; col_i < cols; col_i++) {
                if (file.eof())
                    throw FileException("LOAD: invalid file format.");
                file >> value;
                other.matrix[row_i][col_i] = value;
            }
        }
        if (file.eof())
            throw FileException("LOAD: invalid file format.");
        resize(rows, cols);
        matrix = other.matrix;
    } catch(std::bad_alloc&) {
        std::cout << "Unable to allocate memory." << std::endl;
    }
}

void Matrix::print() const {
    for (int row_i = 0; row_i < rows; row_i++) {
        for (int col_i = 0; col_i < cols; col_i++)
            std::cout << matrix[row_i][col_i] << " ";
        std::cout << "\n";
    }
}

MatrixException::MatrixException(const std::string& msg) : logic_error(msg) {
}

const char* MatrixException::what() const noexcept {
        return logic_error::what();
}

FileException::FileException(const std::string& msg) : runtime_error(msg) {}

const char* FileException::what() const noexcept {
        return runtime_error::what();
}