
#include "Matrix.h"

Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols) {
    data = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        data[i] = new int[cols];
    }
}

Matrix::~Matrix() {
    for (int i = 0; i < rows; ++i) {
        delete[] data[i];
    }
    delete[] data;
}

void Matrix::setElement(int row, int col, int value) {
    data[row][col] = value;
}

int Matrix::getRows() const {
    return rows;
}

int Matrix::getCols() const {
    return cols;
}

int Matrix::getElement(int row, int col) const {
    return data[row][col];
}

void Matrix::display() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << data[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

Matrix* Matrix::add(const Matrix& other) const {
    Matrix* result = new Matrix(getRows(), getCols());

    for (int i = 0; i < rows; ++i) {
        int m = 0;
        for (int j = 0; j < cols; ++j) {
            m = getElement(i, j) + other.getElement(i, j);

            result->setElement(i, j, m);
        }

    }

    return result;
}


Matrix* Matrix::multiply(const Matrix& other) const {
    if (getCols() != other.getRows()) {
        // ѕроверка на согласованность размеров дл€ умножени€ матриц
        std::cout << "Ќевозможно умножить матрицы: неправильные размеры" << std::endl;
        return nullptr;
    }

    Matrix* result = new Matrix(getRows(), other.getCols());

    for (int i = 0; i < getRows(); ++i) {
        for (int j = 0; j < other.getCols(); ++j) {
            int sum = 0;
            for (int k = 0; k < getCols(); ++k) {
                sum += getElement(i, k) * other.getElement(k, j);
            }
            result->setElement(i, j, sum);
        }
    }
    return result;
}






void Matrix::inputFromKeyboard() {
    std::cout << "¬ведите элементы матрицы:" << std::endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int value;
            std::cout << "Ёлемент [" << i << "][" << j << "]: ";
            std::cin >> value;
            setElement(i, j, value);
        }
    }
}