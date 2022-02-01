#include <iostream>
#include <Windows.h>

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int year;

    std::cout << "Введите интересующий вас год: ";    
    std::cin >> year;

    if (year % 4 == 0 && year % 100 != 0) {
        std::cout << year << " - високосный год!\n";
    }
    else if (year % 400 == 0) {
        std::cout << year << " - високосный год!\n";
    }
    else {
        std::cout << year << " - НЕ високосный год.\n";
    }
}