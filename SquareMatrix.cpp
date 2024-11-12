#include "SquareMatrix.h"
SquareMatrix::SquareMatrix(int size) : Matrix(size, size) {}

SquareMatrix* SquareMatrix::add(const Matrix& other) const {
    SquareMatrix* result = new SquareMatrix(getRows());
    for (int i = 0; i < getRows(); ++i) {
        int p = 0;
        for (int j = 0; j < getCols(); ++j) {
            p = getElement(i, j) + other.getElement(i, j);

            result->setElement(i, j, p);
        }
    }
    return result;
}
SquareMatrix* SquareMatrix::multiply(const Matrix& other) const {
    if (getCols() != other.getRows()) {
        // Проверка на согласованность размеров для умножения матриц
        std::cout << "Невозможно умножить матрицы: неправильные размеры" << std::endl;
        return nullptr;
    }

    SquareMatrix* result = new SquareMatrix(getRows());

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