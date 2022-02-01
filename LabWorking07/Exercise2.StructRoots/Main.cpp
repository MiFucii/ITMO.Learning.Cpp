#include <Windows.h>
#include <iostream>

struct Roots 
{
    double x1 = NULL;
    double x2 = NULL;

    void printRoots() 
    {
        if (x1 == NULL && x2 == NULL) std::cout << "Нет корней";
        else if (x1 == x2) std::cout << "x1, x2 = " <<x1;
        else std::cout <<"x1 = " << x1 << ", x2 = " << x2;
    }
};

Roots calcRQE(double a, double b, double c)
{
    Roots roots;
    double d = b * b - 4 * a * c;
    if (d > 0)
    {
        roots.x1 = ((-1) * b - sqrt(d)) / (2 * a);
        roots.x2 = ((-1) * b + sqrt(d)) / (2 * a);;
    }
    else if (d == 0)
    {
        roots.x1 = (-1) * b / (2 * a);
        roots.x2 = roots.x1;
    }

    return roots;
}


int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    double a, b, c;

    std::cout << "Для расчета корней квадратного уравнения введите аргументы:\n";
    std::cout << "a = ";
    std::cin >> a;
    std::cout << "b = ";
    std::cin >> b;
    std::cout << "c = ";
    std::cin >> c;

    Roots roots = calcRQE(a, b, c);
    roots.printRoots();
}