#pragma once
#include "Matrix.h"
class SquareMatrix : public Matrix {
public:
    SquareMatrix(int size);

    SquareMatrix* add(const Matrix& other) const override;
    SquareMatrix* multiply(const Matrix& other) const override;
    virtual SquareMatrix* clone() const {
        return new SquareMatrix(*this);
    }
};
