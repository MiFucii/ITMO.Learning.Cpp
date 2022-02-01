#include <Windows.h>
#include <iostream>

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	int a, b, c;
	std::cout << "Введите 3 числа:\n";
	std::cin >> a;
	std::cin >> b;
	std::cin >> c;
	if (a > b && a > c)	std::cout << "Первое число наибольшее из всех.\n";
	else if (b > a && b > c) std::cout << "Второе число наибольшее из всех.\n";
	else std::cout << "Третье число наибольшее из всех.\n";
	return 0;
}

