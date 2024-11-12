
#include "SquareMatrix.h"
#include <iostream>
int main()
{
    setlocale(LC_ALL, "rus");
    int size;
    std::cout << "������� ������ ���������� �������: ";
    std::cin >> size;

    SquareMatrix mat1(size);
    mat1.inputFromKeyboard();

    SquareMatrix mat2(size);
    mat2.inputFromKeyboard();

    std::cout << "������� 1:" << std::endl;
    mat1.display();

    std::cout << "������� 2:" << std::endl;
    mat2.display();

    SquareMatrix* sum = mat1.add(mat2);
    std::cout << "����� ������:" << std::endl;
    sum->display();

    SquareMatrix* product = mat1.multiply(mat2);
    std::cout << "������������ ������:" << std::endl;
    product->display();

    delete product;

    //SquareMatrix transposed = mat1.transpose();
    //std::cout << "����������������� �������:" << std::endl;
    //transposed.display();

    return 0;
}