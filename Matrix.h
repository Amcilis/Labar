#pragma once
#include <iostream>

class Matrix {
private:
    int rows;
    int cols;
    int** data;

public:
    Matrix(int rows, int cols);

    virtual ~Matrix();

    void setElement(int row, int col, int value);

    int getRows() const;

    int getCols() const;

    int getElement(int row, int col) const;

    void display();

    virtual Matrix* add(const Matrix& other) const;

    virtual Matrix* multiply(const Matrix& other) const;


    void inputFromKeyboard();
};

