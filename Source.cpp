
#include "SquareMatrix.h"
#include <iostream>
int main()
{
    setlocale(LC_ALL, "rus");
    int size;
    std::cout << "Введите размер квадратной матрицы: ";
    std::cin >> size;

    SquareMatrix mat1(size);
    mat1.inputFromKeyboard();

    SquareMatrix mat2(size);
    mat2.inputFromKeyboard();

    std::cout << "Матрица 1:" << std::endl;
    mat1.display();

    std::cout << "Матрица 2:" << std::endl;
    mat2.display();

    SquareMatrix* sum = mat1.add(mat2);
    std::cout << "Сумма матриц:" << std::endl;
    sum->display();

    SquareMatrix* product = mat1.multiply(mat2);
    std::cout << "Произведение матриц:" << std::endl;
    product->display();

    delete product;

    //SquareMatrix transposed = mat1.transpose();
    //std::cout << "Транспонированная матрица:" << std::endl;
    //transposed.display();

    return 0;
}