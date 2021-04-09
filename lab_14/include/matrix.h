#ifndef MATRIX_H_
#define MATRIX_H_

#include <vector>
#include <iostream>
#include <exception>

class Matrix {
public:
    Matrix(int rows_ = 0, int cols_ = 0);
    ~Matrix();

    void resize(int rows_, int cols_);
    void add(const Matrix& other);
    void mul(const Matrix& other);
    int get(int row, int col) const;
    void set(int row, int col, int val);
    void read(std::string filename);
    void print() const;
    
private:
    int rows;
    int cols;
    std::vector<std::vector<int>> matrix;
};

class MatrixException : public std::logic_error {
public:
    MatrixException(const std::string& msg);
    const char* what() const noexcept override;
};

class FileException : public std::runtime_error {
public:
    FileException(const std::string& msg);
    const char* what() const noexcept override;
};


#endif /* MATRIX_H_ */