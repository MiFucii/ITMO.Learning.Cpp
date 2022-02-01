#include <Windows.h>
#include <iostream>

class Triangle
{
private:
    double a;
    double b;
    double c;
public:
    Triangle(double s1, double s2, double s3)
    {
        std::string side;
        bool flag = false; 
        double sideSize;

        if (s1 > s2 + s3) { sideSize = s1; side = "A"; flag = true; };
        if (s2 > s1 + s3) { sideSize = s2; side = "B"; flag = true; };
        if (s3 > s2 + s1) { sideSize = s3; side = "C"; flag = true; };
        if (flag) throw ExceptionTriangle(sideSize, side);
        a = s1;
        b = s2;
        c = s3;
    }
    double calcArea()
    {
        double halfP = (a + b + c) / 2;
        return sqrt((halfP * (halfP - a) * (halfP - b) * (halfP - c)));
    }

    class ExceptionTriangle {
    public:
        std::string side;
        double sideValue;
        ExceptionTriangle(double sideValue, std::string side)
        {
            this->side = side;
            this->sideValue = sideValue;
        }
    };
};

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int a, b, c;

    std::cout << "Введите сторону а: ";
    std::cin >> a;
    std::cout << "Введите сторону b: ";
    std::cin >> b;
    std::cout << "Введите сторону с: ";
    std::cin >> c;

    try {
        Triangle t(a, b, c);
        std::cout << "Площадь треугольника равна: " << t.calcArea();
    }
    catch (Triangle::ExceptionTriangle& ex) {
        std::cout << "Ошибка инициализации:\n";
        std::cout << "Длина стороны " << ex.side <<
            " равна " << ex.sideValue << " что болльше суммы двух других сторон и является не допустимым!\n";
    }
}

