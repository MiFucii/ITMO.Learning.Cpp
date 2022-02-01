#include <Windows.h>
#include <iostream>
#include <tuple>

std::tuple<int, double, double> calcRQE(double a, double b, double c)
{
    double x1, x2, flag = -1;
    double d = b * b - 4 * a * c;

    if (d > 0)
    {
        x1 = ((-1) * b - sqrt(d)) / (2 * a);
        x2 = ((-1) * b + sqrt(d)) / (2 * a);;
        flag = 1;
    }
    else if (d == 0)
    {
        x1 = (-1) * b / (2 * a);
        x2 = x1;
        flag = 0;
    }

    return std::make_tuple(flag, x1, x2);
}

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    double a, b, c, x1, x2;
    int flag;

    std::cout << "Для расчета корней квадратного уравнения введите аргументы:\n";
    std::cout << "a = ";
    std::cin >> a;
    std::cout << "b = ";
    std::cin >> b;
    std::cout << "c = ";
    std::cin >> c;

    std::tie(flag, x1, x2) = calcRQE(a, b, c);
    switch (flag)
    {
    case 1:
        std::cout << "x1 = " << x1 << ", x2 = " << x2; break;
    case 0:
        std::cout << "x1, x2 = " << x1; break;
    case (-1):
        std::cout << "Корней нет."; break;
    }
}