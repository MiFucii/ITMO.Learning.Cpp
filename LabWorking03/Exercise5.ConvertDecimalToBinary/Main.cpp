#include <Windows.h>
#include <iostream>

int convertToBinary(int number)
{
    if (number < 2)
        return number;
    else
        return (10 * convertToBinary(number / 2) + number % 2);
}

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int x, binaryX;

    std::cout << "Введите число для перевода в бинарный вид: ";
    std::cin >> x;

    binaryX = convertToBinary(x);
    std::cout << "Бинарное значение введенного числа: " << binaryX;
}
