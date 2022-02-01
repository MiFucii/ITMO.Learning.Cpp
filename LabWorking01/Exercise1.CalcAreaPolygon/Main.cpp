#include <iostream>
#include <vector>
#include <Windows.h>
using namespace std;

struct Point
{
    double x;
    double y;
};

double polygonArea(vector<Point> pcor) {
    double sum1 = 0, sum2 = 0;
    //Копируем первую точку в конец массива точек
    Point p = pcor[0];
    pcor.push_back(p);

    //Используется метод решения «формула шнурков»
    for (int i = 0; i < pcor.size() - 1; i++)
    {
        //Сначала проведём диагональ вниз и вправо косой чертой и посчитаем получившуюся сумму
        sum1 += pcor[i].x * pcor[i + 1].y;
        //Сделаем то же самое, проводя косую черту по диагонали вниз и влево
        sum2 += pcor[i + 1].x * pcor[i].y;
    }
    //Затем вычтем сумму второй группы из первой, возьмём модуль и разделим на 2
    return ((sum1 - sum2) * -1) / 2;
}

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    double x, y;
    int k;
    std::cout << "Введите количество точек: ";
    std::cin >> k;
    vector<Point> pcoordinates;
    for (int i = 0; i < k ; i++)
    {
        std::cout << "Введите координату х " << i + 1 << " точки: ";
        std::cin >> x;
        std::cout << "Введите координату y " << i + 1 << " точки: ";
        std::cin >> y;
        system("Cls");
        Point p{ x, y };

        pcoordinates.push_back(p);
    }

    double area = polygonArea(pcoordinates);
    cout << "\nПлощадь вашей фигуры равна: " << area << "\n";
}